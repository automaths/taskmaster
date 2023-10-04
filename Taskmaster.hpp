#include "utils.hpp"
#include <cstdlib>

class TaskMaster {

public:

    TaskMaster(){
        init_help();
    }

    void init_help() {
        m_help["help"] = "Print a list of available actions\nhelp <action>	Print help for <action>\n";
        m_help["add"] = "add <name> [...]	Activates any updates in config for process/group\n";
        m_help["avail"] = "avail			Display all configured processes\n";
        m_help["clear"] = "clear <name>		Clear a process' log files.\nclear <name> <name>	Clear multiple process' log files\nclear all		Clear all process' log files\n";
        m_help["exit"] = "exit	Exit the supervisor shell.\n";
        m_help["fg"] = "fg <process>	Connect to a process in foreground mode\n		Ctrl-C to exit\n";
        m_help["maintain"] = "*** No help on maintain\n";
        m_help["open"] = "open <url>	Connect to a remote supervisord process.\n		(for UNIX domain socket, use unix:///socket/path)";
        m_help["pid"] = "pid			Get the PID of supervisord.\npid <name>		Get the PID of a single child process by name.\npid all			Get the PID of every child process, one per line.\n";
        m_help["quit"] = "quit	Exit the supervisor shell.\n";
        m_help["reload"] = "reload 		Restart the remote supervisord.\n";
        m_help["remove"] = "remove <name> [...]	Removes process/group from active config\n";
        m_help["reread"] = "reread 			Reload the daemon's configuration files without add/remove\n";
        m_help["restart"] = "restart <name>		Restart a process\nrestart <gname>:*	Restart all processes in a group\nrestart <name> <name>	Restart multiple processes or groups\nrestart all		Restart all processes\n";
        m_help["shutdown"] = "shutdown 	Shut the remote supervisord down.\n";
        m_help["signal"] = "signal <signal name> <name>		Signal a process\nsignal <signal name> <gname>:*		Signal all processes in a group\nsignal <signal name> <name> <name>	Signal multiple processes or groups\nsignal <signal name> all		Signal all processes\n";
        m_help["start"] = "start <name>		Start a process\nstart <gname>:*		Start all processes in a group\nstart <name> <name>	Start multiple processes or groups\nstart all		Start all processes\n";
        m_help["status"] = "status <name>		Get status for a single process\nstatus <gname>:*	Get status for all processes in a group\nstatus <name> <name>	Get status for multiple named processes\nstatus			Get all process status info\n";
        m_help["stop"] = "stop <name>		Stop a process\nstop <gname>:*		Stop all processes in a group\nstop <name> <name>	Stop multiple processes or groups\nstop all		Stop all processes\n";
        m_help["tail"] = "tail [-f] <name> [stdout|stderr] (default stdout)\nEx:\ntail -f <name>		Continuous tail of named process stdout\n			Ctrl-C to exit.\ntail -100 <name>	last 100 *bytes* of process stdout\ntail <name> stderr	last 1600 *bytes* of process stderr\n";
        m_help["update"] = "update			Reload config and add/remove as necessary, and will restart affected programs\nupdate all		Reload config and add/remove as necessary, and will restart affected programs\nupdate <gname> [...]	Update specific groups\n";
        m_help["version"] = "version			Show the version of the remote supervisord process\n";
    }

    void exit_cmd(int p_exitCode) {
        std::exit(p_exitCode);
    }

    void help_cmd(std::vector<std::string> p_args) {
        if (p_args.size() == 0) {
            std::cout << "\ndefault commands (type help <topic>):\n=====================================\nadd    exit      open  reload  restart   start   tail   \navail  fg        pid   remove  shutdown  status  update \nclear  maintail  quit  reread  signal    stop    version\n\n" << std::endl;
        }
        else if (p_args.size() != 1) {
            std::cout << "help		Print a list of available actions\nhelp <action>	Print help for <action>\n" << std::endl;
        }
        else {
            std::cout << m_help[p_args[0]] << std::endl;
        }
    }


    void run(std::string p_command, std::vector<std::string> p_args) {

        if (p_command == "exit") {
            exit_cmd(0);
        }
        else if (p_command == "help") {
            help_cmd(p_args);
        }



        // int exitCode = system(p_command.c_str());
        // std::cout << "the exit code is : " << exitCode << std::endl;




    }


private:

    std::unordered_map<std::string, std::string> m_help;

};