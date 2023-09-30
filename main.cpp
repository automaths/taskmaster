#include "Config.hpp"
#include <yaml-cpp/yaml.h>


int main() {

    YAML::Node l_config = YAML::LoadFile("coucou.yaml");

    Config cfg(l_config);

    return 0;
}