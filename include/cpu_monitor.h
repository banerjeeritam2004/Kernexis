#ifndef CPU_MONITOR_H
#define CPU_MONITOR_H

#include <string>

class CPUMonitor {
public:
    int getCoreCount();
    int getThreadCount();
    double getCPUUsage();
};

#endif
