#include "zkClient.h"
#include "rpcApplication.h"
#include <semaphore.h>
#include "logger.h"
#include <iostream>
#include <string.h>

namespace tinyrpc
{
    void global_watcher(zhandle_t *zh, int type,
                   int state, const char *path, void *watcherCtx)
    {
        /// 回调的消息类型是和会话相关的消息类型
        if (type == ZOO_SESSION_EVENT)  
        {
            /// zkclient和zkserver连接成功
            if (state == ZOO_CONNECTED_STATE)  
            {
                sem_t *sem = (sem_t*)zoo_get_context(zh);
                sem_post(sem);
            }
        }
    }


    ZkClient::ZkClient()
    : zkHandler_(nullptr)
    {
    }

    ZkClient::~ZkClient()
    {
        if(zkHandler_ != nullptr)
        {
            zookeeper_close(zkHandler_);
        } 
    }

    bool ZkClient::ZkConnection()
    {
        std::string ip = Application::getInstance()->getConfig().getConfig("zookeeperip");
        std::string port = Application::getInstance()->getConfig().getConfig("zookeeperport");

        std::string host = ip + ":" + port;
        
        /// 异步调用，直接返回，通过watcher回调实现同步。
        zkHandler_ = zookeeper_init(host.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
        if(zkHandler_ == nullptr)
        {
            LOG_INFO("zookeeper_init error! zkserver %s ", host.c_str());
            return false;
        }

        sem_t sem_;
        sem_init(&sem_, 0, 0);
        zoo_set_context(zkHandler_, &sem_);

        sem_wait(&sem_);
        
        LOG_INFO("connect zkserver %s success", host.c_str());
        return true;
    }

    void ZkClient::registerToZkServer(const char *path, const char *data, int datalen, int state)
    {
        char path_buffer[128];
        int bufferSize = sizeof(path_buffer);
        int flag;
        flag = zoo_exists(zkHandler_, path, 0, nullptr);
        if(flag == ZNONODE)
        {
            flag = zoo_create(zkHandler_, path, data, datalen,
			    &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferSize);
            if(flag == ZOK)
            {
                LOG_INFO("create Node  path: %s success", path);
            }
            else
            {
                LOG_ERROR("create Node path: %s failed", path);
                exit(EXIT_FAILURE);
            }
        }   
    }

    String_vector ZkClient::getServerMethodChlid(const char* path)
    {
        String_vector methodChild_;
        memset(&methodChild_, 0, sizeof(methodChild_));

        char buffer[64];
        int bufferlen = sizeof(buffer);
        int flag = zoo_get_children(zkHandler_, path, 0, &methodChild_);
        if (flag != ZOK)
        {
            LOG_ERROR("get Service %s failed", path);
            return methodChild_;
        }
        else
        {
            return methodChild_;
        }
    }

} // namespace tinyrpc