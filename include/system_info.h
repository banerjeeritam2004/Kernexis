#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <string>

class SystemInfo {
public:
    std::string getOSInfo();
    std::string getKernelInfo();
    std::string getCPUInfo();
    std::string getArchitecture();
    std::string getUptime();
};

#endif
