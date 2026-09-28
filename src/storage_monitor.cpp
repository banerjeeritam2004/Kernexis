#include "../include/storage_monitor.h"

#include <sys/statvfs.h>
#include <sstream>
#include <iomanip>

std::string StorageMonitor::getStorageInfo() {
    struct statvfs storage;

    if (statvfs("/", &storage) != 0) {
        return "Unable to read storage information";
    }

    double total =
        static_cast<double>(storage.f_blocks) * storage.f_frsize;

    double available =
        static_cast<double>(storage.f_bavail) * storage.f_frsize;

    double used = total - available;

    double totalGB =
        total / (1024.0 * 1024.0 * 1024.0);

    double usedGB =
        used / (1024.0 * 1024.0 * 1024.0);

    double availableGB =
        available / (1024.0 * 1024.0 * 1024.0);

    double usage = 0.0;

    if (total > 0) {
        usage = (used / total) * 100.0;
    }

    std::stringstream result;

    result << std::fixed << std::setprecision(2);

    result << "Total Storage     : " << totalGB << " GB\n";
    result << "Used Storage      : " << usedGB << " GB\n";
    result << "Available Storage : " << availableGB << " GB\n";
    result << "Storage Usage     : " << usage << "%";

    return result.str();
}
double StorageMonitor::getStorageUsage() {
    struct statvfs storage;

    if (statvfs("/", &storage) != 0) {
        return 0.0;
    }

    double total =
        static_cast<double>(storage.f_blocks) * storage.f_frsize;

    double available =
        static_cast<double>(storage.f_bavail) * storage.f_frsize;

    double used = total - available;

    if (total == 0) {
        return 0.0;
    }

    return (used / total) * 100.0;
}
