#include "../include/system_info.h"
#include <fstream>
#include <sstream>
#include <sys/utsname.h>

std::string SystemInfo::getOSInfo() {
    std::ifstream file("/etc/os-release");
    std::string line;

    while (std::getline(file, line)) {
        if (line.rfind("PRETTY_NAME=", 0) == 0) {
            return line.substr(13);
        }
    }

    return "Unknown";
}

std::string SystemInfo::getKernelInfo() {
    struct utsname info;

    if (uname(&info) == 0) {
        return info.release;
    }

    return "Unknown";
}

std::string SystemInfo::getCPUInfo() {
    std::ifstream file("/proc/cpuinfo");
    std::string line;

    while (std::getline(file, line)) {
        if (line.rfind("model name", 0) == 0) {
            size_t pos = line.find(':');

            if (pos != std::string::npos) {
                return line.substr(pos + 2);
            }
        }
    }

    return "Unknown";
}

std::string SystemInfo::getArchitecture() {
    struct utsname info;

    if (uname(&info) == 0) {
        return info.machine;
    }

    return "Unknown";
}

std::string SystemInfo::getUptime() {
    std::ifstream file("/proc/uptime");
    double uptime;

    if (file >> uptime) {
        long seconds = static_cast<long>(uptime);

        long hours = seconds / 3600;
        long minutes = (seconds % 3600) / 60;

        std::stringstream result;
        result << hours << " hours " << minutes << " minutes";

        return result.str();
    }

    return "Unknown";
}
