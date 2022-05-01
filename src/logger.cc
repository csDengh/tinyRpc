#include "logger.h"
#include <iostream>


namespace tinyrpc
{

    void Logger::pushLoger(std::string logger)
    {
        loggerQueueObj_.push(logger);
    }

    void Logger::setLoggerLevel(loggerLevel level)
    {
        curLoggerLevel_ = level;
    }

    std::string Logger::loggerLevelToString(loggerLevel level)
    {
        switch(level)
        {
            case INFO: return "INFO";
                break;

            case ERROR: return "ERROR";
                break;

            case DEBUG: return  "DEBUG";
                break;

            case FATAL: return  "FATAL";
                break;
        }
    }

    Logger::Logger()
    {
        std::thread loggerThread([&](){
            while(1)
            {
                time_t now = time(nullptr);
                tm *nowTm = localtime(&now);

                char file_name[128];
                sprintf(file_name, "%d-%d-%d-log.txt", nowTm->tm_year+1900, nowTm->tm_mon+1, nowTm->tm_mday);
                FILE *filePtr = fopen(file_name, "a+");
                if(filePtr == nullptr)
                {
                    std::cout << "logger file" <<file_name << "open error"<< std::endl;
                    exit(EXIT_FAILURE);
                }

                std::string msg = loggerQueueObj_.pop();

                char time_buf[128] = {0};
                sprintf(time_buf, "%d:%d:%d=>[%s] ", nowTm->tm_hour, nowTm->tm_min, nowTm->tm_sec, 
                        loggerLevelToString(curLoggerLevel_).c_str());
                msg.insert(0, time_buf);
                msg.append("\n");

                fputs(msg.c_str(), filePtr);
                fclose(filePtr);
            }
        });
        loggerThread.detach();
    }
} // namespace tinyrpc