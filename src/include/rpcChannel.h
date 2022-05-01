#pragma once

#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>


namespace tinyrpc
{


    class rpcChannel : public google::protobuf::RpcChannel
    {
    public:
        /**
         * @details protubuf提供 stub类对象，通过调用stub类对象的rpc方式，其内部调用 channel_->CallMethod()
         * @details 由于RpcChannel的CallMethod为虚函数，所以我们可以重写该方法，因此我们可以接管处理逻辑：那就是数据数据序列化，网络发送和回应的接收
         */
        void CallMethod(const google::protobuf::MethodDescriptor* method,
                          google::protobuf::RpcController* controller, const google::protobuf::Message* request,
                          google::protobuf::Message* response, google::protobuf::Closure* done);

    };


} // namespace tinyrpc



