#include "rpcConfig.h"
#include <iostream>

namespace tinyrpc
{

    void Config::loadConfigFile(const char *configFile)
    {
        FILE *pf = fopen(configFile, "r");
        if(pf == nullptr)
        {
            std::cerr <<configFile << "is null" << std::endl;
            exit(EXIT_FAILURE);
        }

        while(!feof(pf))
        {
            char buf[512] = {0};
            fgets(buf, sizeof(buf), pf);
            std::string readLineBuf(buf);
            deleteSpace(readLineBuf);

            if(readLineBuf.empty() || readLineBuf[0] == '#')
            {
                continue;
            }

            int keyEndIdx = readLineBuf.find('=');
            if(keyEndIdx == -1)
            {
                continue;
            }

            std::string key = readLineBuf.substr(0, keyEndIdx);
            deleteSpace(key);

            int endIdx = readLineBuf.find('\n', keyEndIdx+1);
            readLineBuf = readLineBuf.substr(keyEndIdx+1, endIdx-keyEndIdx-1);
            deleteSpace(readLineBuf);
            
            configMap_[key] = readLineBuf;

        }

    }

    std::string Config::getConfig(std::string key)
    {
        if(configMap_.find(key) != configMap_.end())
        {
            return configMap_[key];
        }
        else
        {
            return "";
        }
    }

    void Config::deleteSpace(std::string &src_buf)
    {
        int notSpaceFirstIdx = src_buf.find_first_not_of(' ');
        if(notSpaceFirstIdx != -1)
        {
            src_buf = src_buf.substr(notSpaceFirstIdx, src_buf.size()-notSpaceFirstIdx);
        }

        int notSpaceLastIdx = src_buf.find_last_not_of(' ');
        if(notSpaceLastIdx != -1)
        {
            src_buf = src_buf.substr(0, notSpaceLastIdx+1);
        }
    }

} // namespace tinyrpc