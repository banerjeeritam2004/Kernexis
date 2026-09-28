#include <iostream>
#include <iomanip>
#include "../include/logger.h"
#include "../include/system_info.h"
#include "../include/cpu_monitor.h"
#include "../include/memory_monitor.h"
#include "../include/process_monitor.h"
#include "../include/storage_monitor.h"
#include "../include/diagnostics.h"
#include "../include/live_monitor.h"
#include <vector>
void showMenu() {
    std::cout << "\n========================================\n";
    std::cout << "              KERNEXIS\n";
    std::cout << "     System Diagnostics Framework\n";
    std::cout << "========================================\n";

    std::cout << "1. System Information\n";
    std::cout << "2. CPU Monitoring\n";
    std::cout << "3. Memory Monitoring\n";
    std::cout << "4. Process Monitoring\n";
    std::cout << "5. Storage Monitoring\n";
    std::cout << "6. System Diagnostics\n";
    std::cout << "7. Live Monitoring\n";
    std::cout << "8. Exit\n";

    std::cout << "\nEnter your choice: ";
}
void showSystemInformation() {
    SystemInfo system;

    std::cout << "\n===== SYSTEM INFORMATION =====\n";

    std::cout << "Operating System : "
              << system.getOSInfo() << '\n';

    std::cout << "Kernel Version   : "
              << system.getKernelInfo() << '\n';

    std::cout << "CPU              : "
              << system.getCPUInfo() << '\n';

    std::cout << "Architecture     : "
              << system.getArchitecture() << '\n';

    std::cout << "System Uptime    : "
              << system.getUptime() << '\n';
}

void showCPUInformation() {
    CPUMonitor cpu;

    std::cout << "\n===== CPU INFORMATION =====\n";

    std::cout << "CPU Cores      : "
              << cpu.getCoreCount() << '\n';

    std::cout << "Logical Threads: "
              << cpu.getThreadCount() << '\n';

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "CPU Usage      : "
              << cpu.getCPUUsage() << "%\n";
}

void showMemoryInformation() {
    MemoryMonitor memory;

    std::cout << "\n===== MEMORY INFORMATION =====\n";

    std::cout << "Total Memory     : "
              << memory.getTotalMemory() << " GB\n";

    std::cout << "Available Memory : "
              << memory.getAvailableMemory() << " GB\n";

    std::cout << "Used Memory      : "
              << memory.getUsedMemory() << " GB\n";

    std::cout << "Memory Usage     : "
              << memory.getMemoryUsage() << "%\n";
}

void showProcessInformation() {
    ProcessMonitor processMonitor;

    std::vector<ProcessInfo> processes =
        processMonitor.getProcesses();

    std::cout << "\n===== RUNNING PROCESSES =====\n";

    std::cout << "Total Processes : "
              << processes.size() << "\n\n";

    std::cout << std::left
              << std::setw(10) << "PID"
              << std::setw(30) << "NAME"
              << "STATE\n";

    std::cout << "-----------------------------------------------\n";

    int count = 0;

    for (const auto& process : processes) {
        std::cout << std::left
                  << std::setw(10) << process.pid
                  << std::setw(30) << process.name
                  << process.state << '\n';

        count++;

        if (count >= 20) {
            break;
        }
    }
}

void showStorageInformation() {
    StorageMonitor storage;

    std::cout << "\n===== STORAGE INFORMATION =====\n";
    std::cout << storage.getStorageInfo() << '\n';
}

void showDiagnostics() {
    CPUMonitor cpu;
    MemoryMonitor memory;
    StorageMonitor storage;
    Diagnostics diagnostics;

    double cpuUsage = cpu.getCPUUsage();
    double memoryUsage = memory.getMemoryUsage();
    double storageUsage = storage.getStorageUsage();

    std::cout << "\n===== SYSTEM DIAGNOSTICS =====\n";

    std::cout << diagnostics.checkCPU(cpuUsage) << '\n';
    std::cout << diagnostics.checkMemory(memoryUsage) << '\n';
    std::cout << diagnostics.checkStorage(storageUsage) << '\n';
}

void showLiveMonitoring() {
    LiveMonitor liveMonitor;

    std::cout << "\n===== LIVE MONITORING =====\n";
    std::cout << "Starting live monitoring...\n";

    liveMonitor.start(5);
}
int main() {
    Logger logger;

    logger.info("Kernexis application started");

    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                showSystemInformation();
                break;

            case 2:
                showCPUInformation();
                break;

            case 3:
                showMemoryInformation();
                break;

            case 4:
                showProcessInformation();
                break;

            case 5:
                showStorageInformation();
                break;

            case 6:
                showDiagnostics();
                break;

            case 7:
                showLiveMonitoring();
                break;

            case 8:
                logger.info("System monitoring completed");
                std::cout << "\nExiting Kernexis...\n";
                return 0;

            default:
                std::cout << "\nInvalid choice. Please try again.\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
}
