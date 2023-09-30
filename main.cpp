#include <iostream>
#include <yaml-cpp/yaml.h>

int main() {

    std::cout << "Hello, World!" << std::endl;

    YAML::Node config = YAML::LoadFile("config_ex.yml");

    return 0;
}