#include "rpcApplication.h"
#include "operation.pb.h"
#include "rpcProvider.h"

class PrividerOperation: public operation::Operation
{
public:

    int64_t add(int32_t nums1, int32_t nums2)
    {
        std::cout <<nums1 <<nums2 << std::endl;
        return nums1 + nums2;
    }

    void Add(::google::protobuf::RpcController* controller,
                       const ::operation::AddRequest* request,
                       ::operation::AddResponse* response,
                       ::google::protobuf::Closure* done)
    {
        int64_t ans = add(request->nums1(), request->nums2());
        
        response->set_ans(ans);

        operation::ResultHead resultHead_;
        resultHead_.set_error(1);
        resultHead_.set_errormsg("success");
        response->set_allocated_resulthead(&resultHead_);

        done->Run();
    }

};




int main(int argc, char**argv)
{
    tinyrpc::Application::Init(argc, argv);
    tinyrpc::rpcProvider rpcProvider_;
    
    PrividerOperation prividerOperation;
    rpcProvider_.registerService(&prividerOperation);

    rpcProvider_.run();

    return 0;
}