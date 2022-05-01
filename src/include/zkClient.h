#pragma once
#include <zookeeper/zookeeper.h>

namespace tinyrpc
{
    /**
     * @brief zk封装类
     */
    class ZkClient
    {
    public:
        ZkClient();
        ~ZkClient();

        /**
         * @brief 连接到zk服务器
         */
        bool ZkConnection();

        /**
         * @brief 将服务注册到zk服务器
         */
        void registerToZkServer(const char *path, const char *data, int datalen, int state);

        /**
         * @brief 返回提供服务的服务器列表
         */
        String_vector getServerMethodChlid(const char* path);

    private:
        /// zk连接句柄
        zhandle_t *zkHandler_;
    };
} // namespace tinyrpc
