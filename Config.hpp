#include <iostream>
#include <string>
#include <exception>
#include <unordered_map>
#include "utils.hpp"

class Config {

public:

    Config(std::string p_filename) {
        std::string l_fileContent = file2string(p_filename);
        std::string l_line;
        std::string l_key;
        std::string l_value;
        std::stringstream l_stream(l_fileContent);
        while (std::getline(l_stream, l_line)) {
            if (l_line[0] == '#') {
                continue;
            }
            std::stringstream l_lineStream(l_line);
            std::getline(l_lineStream, l_key, ':');
            std::getline(l_lineStream, l_value);
            m_config[l_key] = l_value;
        }
    }

    void printConfig() {
        for (auto& l_pair : m_config) {
            std::cout << l_pair.first << " = " << l_pair.second << std::endl;
        }
    }

private:

    std::unordered_map<std::string, std::string> m_config;
};
