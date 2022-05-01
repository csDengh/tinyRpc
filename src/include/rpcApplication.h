#pragma once

#include "rpcConfig.h"


namespace tinyrpc
{

    /**
     * @brief 服务器初始化类
     */
    class Application
    {
    public:
        static Application* getInstance()
        {
            static Application application_;
            return &application_;
        }

        /**
         * @brief 根据输入读取配置
         */

        static void Init(int argc, char** argv);
        
        /**
         * @brief 获得配置类对象
         */    
        static Config getConfig();

    private:
        static Config config_;
        Application() = default;
    };
    
} // namespace tinyrpc
