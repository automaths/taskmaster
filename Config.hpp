#include "utils.hpp"

class Config {

public:

    Config(std::string p_filename) {
        std::string l_fileContent = file2string(p_filename);
        std::string l_line;
        std::string l_key;
        std::string l_mapkey;
        std::string l_value;
        std::stringstream l_stream(l_fileContent);
        while (std::getline(l_stream, l_line)) {
            if (l_line.empty()) {
                continue;
            }
            else if (l_line.find_first_not_of(' ') == 0) {
                l_key = l_line.substr(0, l_line.find_last_not_of(" :") + 1);
                m_config.push_back(std::make_pair(l_key, std::unordered_map<std::string, std::string>()));
            }
            else if (l_line.find_first_not_of(' ') == 2) {
                l_mapkey = l_line.substr(2, l_line.find_first_of(':'));
                l_value = l_line.substr(l_line.find_first_of(':') + 1, l_line.find_last_not_of(" ") + 1);
                m_config.back().second[l_mapkey] = l_value;
            }
            else {
                throw std::runtime_error("Invalid config file format.");
            }
        }
    }

    void printConfig() {
        for (auto& l_section : m_config) {
            std::cout << l_section.first << std::endl;
            for (auto& l_keyValue : l_section.second) {
                std::cout << "    " << l_keyValue.first << " : " << l_keyValue.second << std::endl;
            }
        }
    }

private:

    std::vector<std::pair<std::string, std::unordered_map<std::string, std::string>>> m_config;
};
