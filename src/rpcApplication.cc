#include "rpcApplication.h"

#include <iostream>
#include <unistd.h>


namespace tinyrpc
{
    void ShowArgsHelp()
    {
        std::cout<<"format: command -i <configfile>" << std::endl;
    }

    Config Application::config_;

    void Application::Init(int argc, char** argv)
    {
        if(argc < 2)
        {
            std::cerr << "invaild input" << std::endl;
        }

        int c = 0;
        std::string config_file;
        while((c = getopt(argc, argv, "i:")) != -1)
        {
            switch (c)
            {
            case 'i':
                config_file = optarg;
                break;
            case '?':
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            case ':':
                ShowArgsHelp();
                exit(EXIT_FAILURE);
            default:
                break;
            }
        }
        config_.loadConfigFile(config_file.c_str());

    }



    Config Application::getConfig()
    {
        return config_;
    }



    
} // namespace tinyrpc