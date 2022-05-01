#include "operation.pb.h"
#include "rpcChannel.h"
#include "rpcController.h"
#include "rpcApplication.h"

int main(int argc, char ** argv)
{
    tinyrpc::Application::Init(argc, argv);

    tinyrpc::rpcChannel rpcChannel_;
    operation::Operation_Stub operationStub_(&rpcChannel_);

    operation::AddRequest addRequest_;
    addRequest_.set_nums1(1);
    addRequest_.set_nums2(1);

    operation::AddResponse addResponse_;

    tinyrpc::MprpcController controller;

    operationStub_.Add(&controller, &addRequest_, &addResponse_, nullptr);

    if(controller.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if(addResponse_.resulthead().error() < 0)
        {
            std::cout << "failed " << std::endl;
        }
        else
        {
            std::cout << addResponse_.ans() << std::endl;
        } 
    }


    return 0;
}

