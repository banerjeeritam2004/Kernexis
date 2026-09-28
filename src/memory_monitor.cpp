#include "../include/memory_monitor.h"

#include <fstream>
#include <string>

double MemoryMonitor::getTotalMemory() {
    std::ifstream file("/proc/meminfo");

    std::string name;
    double value;
    std::string unit;

    while (file >> name >> value >> unit) {
        if (name == "MemTotal:") {
            return value / (1024.0 * 1024.0);
        }
    }

    return 0.0;
}

double MemoryMonitor::getAvailableMemory() {
    std::ifstream file("/proc/meminfo");

    std::string name;
    double value;
    std::string unit;

    while (file >> name >> value >> unit) {
        if (name == "MemAvailable:") {
            return value / (1024.0 * 1024.0);
        }
    }

    return 0.0;
}

double MemoryMonitor::getUsedMemory() {
    return getTotalMemory() - getAvailableMemory();
}

double MemoryMonitor::getMemoryUsage() {
    double total = getTotalMemory();

    if (total == 0.0) {
        return 0.0;
    }

    return (getUsedMemory() / total) * 100.0;
}
