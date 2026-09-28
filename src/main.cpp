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
int main() {
    SystemInfo system;
    CPUMonitor cpu;
    MemoryMonitor memory;

    std::cout << "============================================\n";
    std::cout << "                 KERNEXIS\n";
    std::cout << " Linux System Diagnostics and Resource Monitor\n";
    std::cout << "============================================\n\n";

    // System Information
    std::cout << "===== SYSTEM INFORMATION =====\n";

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


    // CPU Information
    std::cout << "\n===== CPU INFORMATION =====\n";

    std::cout << "CPU Cores       : "
              << cpu.getCoreCount() << '\n';

    std::cout << "Logical Threads : "
              << cpu.getThreadCount() << '\n';

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "CPU Usage       : "
              << cpu.getCPUUsage() << "%\n";


    // Memory Information
    std::cout << "\n===== MEMORY INFORMATION =====\n";

    std::cout << "Total Memory     : "
              << memory.getTotalMemory() << " GB\n";

    std::cout << "Available Memory : "
              << memory.getAvailableMemory() << " GB\n";

    std::cout << "Used Memory      : "
              << memory.getUsedMemory() << " GB\n";

    std::cout << "Memory Usage     : "
              << memory.getMemoryUsage() << "%\n";


    std::cout << "\n============================================\n";
    std::cout << "              End of Report\n";
    std::cout << "============================================\n";
// Process Information
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

std::cout << "---------------------------------------------\n";

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
StorageMonitor storage;

std::cout << "\n===== STORAGE INFORMATION =====\n";
std::cout << storage.getStorageInfo() << "\n";
Diagnostics diagnostics;

double cpuUsage = cpu.getCPUUsage();
double memoryUsage = memory.getMemoryUsage();

// Storage usage will be calculated separately
std::cout << "\n===== SYSTEM DIAGNOSTICS =====\n";

std::cout << diagnostics.checkCPU(cpuUsage) << '\n';
std::cout << diagnostics.checkMemory(memoryUsage) << '\n';
double storageUsage = storage.getStorageUsage();

std::cout << diagnostics.checkStorage(storageUsage) << '\n';

Logger logger;

logger.info("Kernexis application started");
logger.info("System monitoring completed");

LiveMonitor liveMonitor;


std::cout << "\n===== LIVE MONITORING =====\n";
std::cout << "Starting live monitoring...\n";

liveMonitor.start(5);
    return 0;



}
