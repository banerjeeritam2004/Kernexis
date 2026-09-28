#ifndef PROCESS_MONITOR_H
#define PROCESS_MONITOR_H

#include <string>
#include <vector>

struct ProcessInfo {
    int pid;
    std::string name;
    std::string state;
};

class ProcessMonitor {
public:
    std::vector<ProcessInfo> getProcesses();
};

#endif
