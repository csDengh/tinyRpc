#pragma once

#include "loggerQueue.h"
#include <thread>
#include <string>


/**
 * @brief 将日志输出到文件
 * @details 单例获取Logger对象，设置日志级别，写入到文件
 */
#define LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger *logger = tinyrpc::Logger::getInstance(); \
        logger->setLoggerLevel(tinyrpc::Logger::INFO); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger->pushLoger(c); \
    } while(0) \

#define LOG_ERROR(logmsgformat, ...) \
    do \
    {  \
        Logger *logger = tinyrpc::Logger::getInstance(); \
        logger->setLoggerLevel(tinyrpc::Logger::ERROR); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger->pushLoger(c); \
    } while(0) \

#define LOG_DEBUG(loggerformat, ...) \
    do \
    {\
        Logger *logger = tinyrpc::Logger::getInstance();\
        logger->setLoggerLevel(tinyrpc::Logger::DEBUG); \
        char c[1024]={0}; \
        snprintf(c, 1024, loggerformat, ##__VA_ARGS__); \
        logger->pushLoger(c);\
    } while(0) \

#define LOG_FATAL(loggerformat, ...) \
    do \
    {\
        Logger *logger = tinyrpc::Logger::getInstance();\
        logger->setLoggerLevel(tinyrpc::Logger::FATAL); \
        char c[1024]={0}; \
        snprintf(c, 1024, loggerformat, ##__VA_ARGS__); \
        logger->pushLoger(c);\
        exit(-1); \
    }while(0) \

namespace tinyrpc
{
    /**
     * @brief 日志类
     */
    class Logger
    {
    public:

        /**
         * @brief 日志级别
         */
        enum loggerLevel
        {
            INFO,
            ERROR,
            DEBUG,
            FATAL,
        };

        static Logger* getInstance()
        {
            static Logger logger_;
            return &logger_;
        }

        /**
         * @brief 写入到队列
         * @details 子线程写入到磁盘文件
         */
        void pushLoger(std::string logger);

        /**
         * @brief 设置日志级别
         */
        void setLoggerLevel(loggerLevel level);

        /**
         * @brief 日志级别转为string
         */
        std::string loggerLevelToString(loggerLevel level);

    private:
        Logger();
        Logger(const Logger&) = delete;
        Logger operator=(const Logger&) = delete;

        /// 日志队列
        LoggerQueue<std::string> loggerQueueObj_;
        /// 日志级别
        loggerLevel curLoggerLevel_;
    };
} // namespace tinyrpc
