#pragma once

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

#include <memory>
#include <vector>
#include <mutex>


namespace tinyrpc
{
    /**
     * @brief 负载均衡的方式
     */
    enum loadBalanceEnum
    {
        RANDOMCHOICE,
        RoundRobinCHOICE,
        HASHCHOICE
    };

    /**
     * @brief 负载均衡抽象模板类
     */
    template<class T>
    class LoadBalanceStrategy
    {
    public:
        using ptr = std::shared_ptr<LoadBalanceStrategy<T>>;
        virtual ~LoadBalanceStrategy() {};

        virtual T& select(std::vector<T>& choiceList) = 0;
    };

    /**
     * @brief random负载均衡模板类
     */
    template<class T>
    class RandomChoice: public LoadBalanceStrategy<T>
    {
    public:

        T& select(std::vector<T>& choiceList)
        {
            srand((unsigned)time(nullptr));
            return choiceList[rand() % choiceList.size()];
        }
    };

    /**
     * @brief Round Robin负载均衡模板类
     */
    template<class T>
    class RoundRobin: public LoadBalanceStrategy<T>
    {
    public:
        T& select(std::vector<T>& choiceList)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if(idx>= choiceList.size()) idx = 0;
            return choiceList[idx++];
        }
    
    private:
        int idx;
        std::mutex mutex_;
    };


    /**
     * @brief 获得本机host
     */
    static std::string GetLocalHost();

    /**
     * @brief ip hash负载均衡模板类
     */
    template<class T>
    class HashStrategy: public LoadBalanceStrategy<T>
    {
    public:

        T& select(std::vector<T>& choiceList)
        {
            static std::string host = GetLocalHost();
            if(host.empty())
            {
                return RandomChoice<T>().select(choiceList);
            }
            size_t hashIdx = std::hash<std::string>()(host);
            return choiceList[hashIdx % choiceList.size()];
        }

    };

    /**
     * @brief 负载均衡模板类
     */
    template<class T>
    class LoadBalance
    {
    public:
        static typename LoadBalanceStrategy<T>::ptr  getStrategy(loadBalanceEnum strategy)
        {
            switch (strategy)
            {
            case RANDOMCHOICE: return randomStrategy_;
            case RoundRobinCHOICE: return hashStrategy_;
            case HASHCHOICE: return std::make_shared<HashStrategy<T>>();
            default: return randomStrategy_;
            }
        }
    
    private:
        static typename LoadBalanceStrategy<T>::ptr randomStrategy_;
        static typename LoadBalanceStrategy<T>::ptr hashStrategy_;
    };

    template<class T>
    typename LoadBalanceStrategy<T>::ptr LoadBalance<T>::randomStrategy_ = std::make_shared<RandomChoice<T>>();

    template<class T>
    typename LoadBalanceStrategy<T>::ptr LoadBalance<T>::hashStrategy_ = std::make_shared<HashStrategy<T>>();


    std::string GetLocalHost()
    {
        int sockfd;
        struct ifconf ifconf;
        struct ifreq *ifreq = nullptr;
        char buf[512];

        ifconf.ifc_len =512;
        ifconf.ifc_buf = buf;
        if ((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0)
        {
            return std::string{};
        }
        ioctl(sockfd, SIOCGIFCONF, &ifconf); 

        ifreq = (struct ifreq*)ifconf.ifc_buf;
        for (int i=(ifconf.ifc_len/sizeof (struct ifreq)); i>0; i--)
        {
            if(ifreq->ifr_flags == AF_INET){ 
                if (ifreq->ifr_name == std::string("eth0")) {
                    return std::string(inet_ntoa(((struct sockaddr_in*)&(ifreq->ifr_addr))->sin_addr));
                }
                ifreq++;
            }
        }
        return std::string{};
    }

} // namespace tinyrpc
