#pragma once

#include <unordered_map>



namespace tinyrpc
{
    /**
     * @brief 配置类
     */
    class Config
    {
    public:
        /**
         * @brief 解析配置文件
         */
        void loadConfigFile(const char *configFile);

        /**
         * @brief 根据配置文件的key返回对应的value
         */
        std::string getConfig(std::string key);
    private:

        /**
         * @brief 删除多余的空格
         */
        void deleteSpace(std::string &src_buf);
        /// 配置文件的key-value
        std::unordered_map<std::string, std::string> configMap_;
    };

} // namespace tinyrpc



