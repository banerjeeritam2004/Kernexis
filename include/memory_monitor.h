#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

class MemoryMonitor {
public:
    double getTotalMemory();
    double getAvailableMemory();
    double getUsedMemory();
    double getMemoryUsage();
};

#endif
