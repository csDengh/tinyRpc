#include "rpcChannel.h"
#include "rpcheader.pb.h"
#include "zkClient.h"
#include "loadBalance.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>



namespace tinyrpc
{
    void rpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const google::protobuf::Message* request,
                          google::protobuf::Message* response, google::protobuf::Closure* done)
    {

        /// 组装请求消息： 头部固定四字节（表示rpcheader长度）+ rpcheader（servericeName + methodName + agrcSize） + argc

        const google::protobuf::ServiceDescriptor* serviceDescPtr = method->service();

        std::string requestMsg =request->SerializeAsString();

        std::string serviceName = serviceDescPtr->name();
        std::string methodName = method->name();
        uint32_t argcSize = requestMsg.size();

        tinyrpc::rpcheader requsetHeader;
        requsetHeader.set_servicename(serviceName);
        requsetHeader.set_methodname(methodName);
        requsetHeader.set_argcsize(argcSize);
        std::string requestHeaderSerized = requsetHeader.SerializeAsString();
        
        uint32_t requsetHeaderSize = requestHeaderSerized.size();

        std::string rpcRequestSerized;
        rpcRequestSerized.insert(0, std::string((char*)&requsetHeaderSize, 4));
        rpcRequestSerized += requestHeaderSerized;
        rpcRequestSerized += requestMsg;

        /// 消息请求序列化后，将消息请求发送到服务器
        /// 那么首先先从服务注册中心获取可提供服务的服务器

        ZkClient zkClient_;
        if(!zkClient_.ZkConnection())
        {
            controller->SetFailed("register center  connect failed");
            return;
        }

        std::string requestServicePath = "/" + serviceName + "/" + methodName;
        String_vector methodPath_ = zkClient_.getServerMethodChlid(requestServicePath.c_str());

        if(methodPath_.count <= 0)
        {
            controller->SetFailed("register center  no coresponding service method");
            return;
        }

        std::vector<std::string> methodPathVec;
        for(int i=0; i<methodPath_.count; ++i)
        {
            methodPathVec.push_back(methodPath_.data[i]);
        }

        /// 得到提供服务的服务器列表后，进行负载均衡挑选一个服务器
        tinyrpc::LoadBalanceStrategy<std::string>::ptr loadBalanceStrategy_ = 
                    tinyrpc::LoadBalance<std::string>::getStrategy(tinyrpc::RANDOMCHOICE);
        std::string selecedChoice =  loadBalanceStrategy_->select(methodPathVec);
        
        int idx = selecedChoice.find(":");
        if(idx == -1)
        {
            controller->SetFailed("register center  no coresponding service method");
            return;
        }

        /// 组装请求addr，与服务器进行连接，连接成功发送消息
        std::string ip = selecedChoice.substr(0, idx);
        int port = atoi(selecedChoice.substr(idx+1, selecedChoice.size()-idx).c_str());

        sockaddr_in serverAddr;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
        serverAddr.sin_family = AF_INET;


        int clientFd = socket(AF_INET, SOCK_STREAM, 0);
        if(-1 == clientFd)
        {
            controller->SetFailed("client socket create failed");
            return;
        }

        int ret_conn = connect(clientFd, (sockaddr*)&serverAddr, sizeof(serverAddr));
        if(ret_conn == -1)
        {
            controller->SetFailed("client socket connect failed");
            return;
        }

        int ret_write = write(clientFd, rpcRequestSerized.c_str(), rpcRequestSerized.size());
        if(ret_write == -1)
        {
            controller->SetFailed("client socket write failed");
            return ;
        }

        char recv_buf[1024]={0};
        int recv_size = 0;


        /// 消息发送成功，阻塞等待接收结果
        recv_size = read(clientFd, recv_buf, sizeof(recv_buf));

        if(recv_size == -1)
        {
            controller->SetFailed("client socket read failed");
            close(clientFd);
            return ;
        }

        if(!response->ParseFromArray(recv_buf, recv_size))
        {
            controller->SetFailed("client socket parse failed");
            close(clientFd);
            return ;
        }

        /// 接收完毕，关闭连接
        close(clientFd);
    } 


} // namespace tinyrpc