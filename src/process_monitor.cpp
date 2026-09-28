#include "../include/process_monitor.h"

#include <dirent.h>
#include <fstream>
#include <string>
#include <cctype>

std::vector<ProcessInfo> ProcessMonitor::getProcesses() {
    std::vector<ProcessInfo> processes;

    DIR* directory = opendir("/proc");

    if (directory == nullptr) {
        return processes;
    }

    struct dirent* entry;

    while ((entry = readdir(directory)) != nullptr) {

        std::string directoryName = entry->d_name;

        if (entry->d_type == DT_DIR &&
            !directoryName.empty() &&
            std::isdigit(directoryName[0])) {

            int pid = std::stoi(directoryName);

            std::string statusPath =
                "/proc/" + directoryName + "/status";

            std::ifstream file(statusPath);

            if (!file.is_open()) {
                continue;
            }

            std::string line;
            std::string name = "Unknown";
            std::string state = "Unknown";

            while (std::getline(file, line)) {

                if (line.rfind("Name:", 0) == 0) {
                    name = line.substr(6);
                }
                else if (line.rfind("State:", 0) == 0) {
                    state = line.substr(7);
                }
            }

            processes.push_back({pid, name, state});
        }
    }

    closedir(directory);

    return processes;
}
