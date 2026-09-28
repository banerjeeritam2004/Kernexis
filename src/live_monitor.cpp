#include "../include/live_monitor.h"
#include "../include/cpu_monitor.h"
#include "../include/memory_monitor.h"
#include "../include/storage_monitor.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

void LiveMonitor::start(int cycles) {
    CPUMonitor cpu;
    MemoryMonitor memory;
    StorageMonitor storage;

    std::thread monitorThread([&]() {

        for (int i = 0; i < cycles; i++) {

            double cpuUsage = cpu.getCPUUsage();
            double memoryUsage = memory.getMemoryUsage();
            double storageUsage = storage.getStorageUsage();

            std::cout << "\n====================================\n";
            std::cout << "        KERNEXIS LIVE MONITOR\n";
            std::cout << "====================================\n";

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "CPU Usage     : "
                      << cpuUsage << "%\n";

            std::cout << "Memory Usage  : "
                      << memoryUsage << "%\n";

            std::cout << "Storage Usage : "
                      << storageUsage << "%\n";

            std::cout << "====================================\n";

            std::this_thread::sleep_for(
                std::chrono::seconds(2)
            );
        }
    });

    monitorThread.join();
}
