#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

namespace tinyrpc
{
    /**
     * @brief 日志队列模板类
     */
    template<typename T>
    class LoggerQueue
    {
    public:

        /**
         * @brief 插入到队列
         */
        void push(const T& logger)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            loggerQueue_.push(logger);
            cond_.notify_one();
        }

        /**
         * @brief 从队列中取出
         */
        T pop()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            while(loggerQueue_.empty())
            {
                cond_.wait(lock);
            }

            T data = loggerQueue_.front();
            loggerQueue_.pop();
            return data;
        }

    private:
        std::queue<T> loggerQueue_;
        std::mutex mutex_;
        std::condition_variable cond_;
    };
} // namespace tinyrpc
