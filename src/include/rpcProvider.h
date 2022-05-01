#pragma once

#include <google/protobuf/service.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Callbacks.h>
#include <unordered_map>
#include "logger.h"

namespace tinyrpc
{

    /**
     * @brief 服务提供方类
     */
    class rpcProvider
    {
    public:
        rpcProvider();
        ~rpcProvider();

        /**
         * @brief 注册服务
         */
        void registerService(google::protobuf::Service* service);

        /**
         * @brief 将注册的服务发送到注册中心，以临时节点的形式存储，注册后，开启事件循环，等待请求的到来
         */
        void run();

    private:
        /**
         * @brief 将service进行封装，一个service下有多个方法
         */
        struct ServiceInfo
        {
            google::protobuf::Service *service_;
            std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> methodsMap_;
        };

        /// muduo的eventloop
        muduo::net::EventLoop eventLoop_;
        /// service的map，key:service的名称->value（serviceInfo）
        std::unordered_map<std::string, ServiceInfo> serviceMap_;
        /// 连接建立和断开的回调
        void connectionCallback_(const muduo::net::TcpConnectionPtr&);
        /// 连接请求的read事件的回调
        void messageCallback_(const muduo::net::TcpConnectionPtr& conn,
                            muduo::net::Buffer* buffer,
                            muduo::Timestamp receiveTime);
        /// 作为google::protobuf::Closure的回调函数，用于最后的发送回应消息
        void sendCallback_(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message *response);
    };

    
} // namespace tinyrpc
