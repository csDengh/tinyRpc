#include "rpcProvider.h"
#include "rpcApplication.h"
#include "zkClient.h"

#include <google/protobuf/descriptor.h>
#include <functional>
#include "rpcheader.pb.h"


namespace tinyrpc
{

    rpcProvider::rpcProvider()
    {
    }

    rpcProvider::~rpcProvider()
    {
        for(auto it = serviceMap_.begin(); it != serviceMap_.end(); ++it)
        {
            delete it->second.service_;
        }
    }

    void rpcProvider::registerService(google::protobuf::Service* service)
    {
        ServiceInfo serviceInfo;

        const google::protobuf::ServiceDescriptor *serviceDescPtr = service->GetDescriptor();
        serviceInfo.service_ = service;

        std::string serviceName = serviceDescPtr->name();
        int methodNums = serviceDescPtr->method_count();
        LOG_INFO("Add service : %s", serviceName.c_str());

        for(int i=0; i<methodNums; ++i)
        {
            const google::protobuf::MethodDescriptor* methodDescPtr = serviceDescPtr->method(i);
            std::string methodName = methodDescPtr->name();
            serviceInfo.methodsMap_[methodName] = methodDescPtr;
            LOG_INFO("Add service: %s : method %s", serviceName.c_str(), methodName.c_str());

        }
        serviceMap_[serviceName] = serviceInfo;

    }

    void rpcProvider::run()
    {
        std::string serverIp = Application::getConfig().getConfig("rpcserverip");
        std::string serverPort = Application::getConfig().getConfig("rpcserverport");

        muduo::net::InetAddress inetAddr(serverIp, atoi(serverPort.c_str()));
        muduo::net::TcpServer server_(&eventLoop_, inetAddr, "rpcProvider1");

        server_.setConnectionCallback(std::bind(
            &rpcProvider::connectionCallback_, this, std::placeholders::_1
        ));

        server_.setMessageCallback(std::bind(
            &rpcProvider::messageCallback_, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3
        ));

        LOG_INFO("servicePrivder ip: %s port: %s", serverIp.c_str(), serverPort.c_str());
        
        /// 将服务注册到注册中心
        ZkClient zkClient_;
        zkClient_.ZkConnection();

        for (auto &service : serviceMap_) 
        {
            std::string servicePath = "/" + service.first;
            zkClient_.registerToZkServer(servicePath.c_str(), nullptr, 0, 0);
            
            for (auto &method : service.second.methodsMap_)
            {
                std::string methodPath = servicePath + "/" + method.first;
                zkClient_.registerToZkServer(methodPath.c_str(), nullptr, 0, 0);
                
                std::string methodPathSomeOne = methodPath + "/" + serverIp + ":" + serverPort;
                zkClient_.registerToZkServer(methodPathSomeOne.c_str(), nullptr, 0, ZOO_EPHEMERAL);
            }
        }

        server_.setThreadNum(4);
        server_.start();
        eventLoop_.loop();
    }


    void rpcProvider::connectionCallback_(const muduo::net::TcpConnectionPtr&conn)
    {
        if(!conn->connected())
        {
            conn->shutdown();
        }
    }

    void rpcProvider::messageCallback_(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buffer,
                            muduo::Timestamp receiveTime)
    {
        /// 接受调用方传过来的消息 头部固定四字节（表示rpcheader长度）+ rpcheader（servericeName + methodName + agrcSize） + argc
        /// 首先先反序列化消息，得到service，service对应的method，函数参数

        std::string recvMsg =  buffer->retrieveAllAsString();

        uint32_t headSize = 0;
        recvMsg.copy((char*)&headSize, 4, 0);

        std::string recvHeadMsg = recvMsg.substr(4, headSize);
        tinyrpc::rpcheader recvRpcHead;

        std::string serviceName;
        std::string methodName;
        int agrcSize=0;

        if(recvRpcHead.ParseFromString(recvHeadMsg))
        {
            serviceName = recvRpcHead.servicename();
            methodName = recvRpcHead.methodname();
            agrcSize = recvRpcHead.argcsize();
        }
        else
        {
            std::cout <<"rpc header parse" << recvHeadMsg << "failed" << std::endl;
            return ;
        }

        std::string rcvRpcArgc = recvMsg.substr(headSize+4, agrcSize);

        /// 根据解析得到的信息，查询本地是否有对应的服务
        ServiceInfo recvRpcServiceInfo;
        if(serviceMap_.find(serviceName) != serviceMap_.end())
        {
            recvRpcServiceInfo = serviceMap_[serviceName];
        }
        else
        {
            std::cout << "service not find" << serviceName <<std::endl;
            return ;
        }

        /// 根据解析得到的信息，查询本地是否有对应的方法
        if(recvRpcServiceInfo.methodsMap_.find(methodName) == recvRpcServiceInfo.methodsMap_.end())
        {
            std::cout << "service" << serviceName << "method not find" << methodName << std::endl;
            return ;
        }


        google::protobuf::Service *service = recvRpcServiceInfo.service_;
        const google::protobuf::MethodDescriptor* method = recvRpcServiceInfo.methodsMap_[methodName];

        google::protobuf::Message *request = service->GetRequestPrototype(method).New();
        request->ParseFromString(rcvRpcArgc);

        google::protobuf::Message *response = service->GetResponsePrototype(method).New();

        google::protobuf::Closure* done = google::protobuf::NewCallback<rpcProvider, const muduo::net::TcpConnectionPtr&, 
                                                            google::protobuf::Message *>(this, &rpcProvider::sendCallback_, conn, response);
        /// 消息处理完毕，调用callMethod执行该对应的发送。该方法会执行提供方的写好的方法
        service->CallMethod(method, nullptr, request, response, done);
    }


    ///  google::protobuf::Closure 的回调函数：将回应序列化发送到调用方
    void rpcProvider::sendCallback_(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message *response)
    {
        std::string responseMsg;
        if(response->SerializeToString(&responseMsg))
        {
            conn->send(responseMsg);
        }
        else
        {
            std::cout << "serialize response failed" << std::endl;
        }
        conn->shutdown();
    }

} // namespace tinyrpc