#ifndef STORAGE_MONITOR_H
#define STORAGE_MONITOR_H

#include <string>

class StorageMonitor {
public:
    std::string getStorageInfo();
    double getStorageUsage();
};

#endif
