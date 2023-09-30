#include <iostream>
#include <string>
#include <exception>
#include <unordered_map>
// #include <yaml-cpp/yaml.h>
#include <yaml-cpp/yaml.h>

class Config {

public:

    Config(YAML::Node &p_config) {



        if (!isValid(p_config)) {
            throw std::runtime_error("Invalid config file");
        }

        for (YAML::iterator it = p_config.begin(); it != p_config.end(); ++it) {
            std::cout << "key: " << it->first << std::endl;
            std::cout << "value: " << it->second << std::endl;
            std::cout << std::endl;
        }
    }

    bool isValid(YAML::Node &p_config) {

        std::cout << p_config.Type() << std::endl;

        if (!p_config.IsMap() || p_config.size() == 0) {
            return false;
        }
        return true;
    }

private:

    std::unordered_map<std::string, std::string> m_config;
};
