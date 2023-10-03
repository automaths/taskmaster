#include "utils.hpp"

std::string file2string(std::string& p_filename) {

    std::ifstream l_file(p_filename);
    if (!l_file.is_open()) {
        throw std::runtime_error("Failed to open the file: " + p_filename);
    }
    std::stringstream l_buffer;
    l_buffer << l_file.rdbuf();
    l_file.close();
    return l_buffer.str();
}