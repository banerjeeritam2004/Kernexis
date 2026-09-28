#include "../include/cpu_monitor.h"

#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <chrono>

int CPUMonitor::getCoreCount() {
    std::ifstream file("/proc/cpuinfo");

    std::string line;
    int cores = 0;

    while (std::getline(file, line)) {
        if (line.rfind("cpu cores", 0) == 0) {
            size_t pos = line.find(':');

            if (pos != std::string::npos) {
                cores = std::stoi(line.substr(pos + 1));
                break;
            }
        }
    }

    return cores;
}

int CPUMonitor::getThreadCount() {
    return std::thread::hardware_concurrency();
}

double CPUMonitor::getCPUUsage() {
    std::ifstream file("/proc/stat");

    std::string cpu;
    long long user1, nice1, system1, idle1;
    long long iowait1, irq1, softirq1, steal1;

    file >> cpu >> user1 >> nice1 >> system1 >> idle1
         >> iowait1 >> irq1 >> softirq1 >> steal1;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    file.clear();
    file.seekg(0);

    long long user2, nice2, system2, idle2;
    long long iowait2, irq2, softirq2, steal2;

    file >> cpu >> user2 >> nice2 >> system2 >> idle2
         >> iowait2 >> irq2 >> softirq2 >> steal2;

    long long idleDelta =
        (idle2 + iowait2) - (idle1 + iowait1);

    long long total1 =
        user1 + nice1 + system1 + idle1 +
        iowait1 + irq1 + softirq1 + steal1;

    long long total2 =
        user2 + nice2 + system2 + idle2 +
        iowait2 + irq2 + softirq2 + steal2;

    long long totalDelta = total2 - total1;

    if (totalDelta == 0) {
        return 0.0;
    }

    return (1.0 - static_cast<double>(idleDelta) / totalDelta) * 100.0;
}
