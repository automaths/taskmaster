#include "Config.hpp"
#include "Taskmaster.hpp"

int main() {

    TaskMaster l_taskmaster;
    Config l_config("config_ex.yml");
    // l_config.printConfig();

    std::string l_command;
    std::vector<std::string> l_args;
    while (1) {
        std::cout << "Taskmaster: ";
        std::getline(std::cin, l_command);
        // parse the command to extract args
        l_taskmaster.run(l_command, l_args);
    }
    return 0;
}