#pragma once
#include <google/protobuf/service.h>
#include <string>


namespace tinyrpc
{
    /**
     * @brief 用户远程调用失败时，可通过该类获得失败信息
     */
    class MprpcController : public google::protobuf::RpcController
    {
    public:
        MprpcController();

        /**
         * @brief 重置信息
         */
        void Reset();

        /**
         * @brief 返回是否失败
         */        
        bool Failed() const;

        /**
         * @brief 返回失败信息
         */
        std::string ErrorText() const;

        /**
         * @brief 用户远程调用失败时，设置错误信息
         */
        void SetFailed(const std::string& reason);


        void StartCancel();
        bool IsCanceled() const;
        void NotifyOnCancel(google::protobuf::Closure* callback);
    private:
        bool m_failed;
        std::string m_errText; 
    };   
} // namespace tinyrpc
