#include "../include/diagnostics.h"

#include <sstream>

std::string Diagnostics::checkCPU(double usage) {
    std::stringstream result;

    if (usage >= 90.0) {
        result << "WARNING: CPU usage is very high.";
    }
    else if (usage >= 75.0) {
        result << "NOTICE: CPU usage is high.";
    }
    else {
        result << "CPU status: Normal.";
    }

    return result.str();
}

std::string Diagnostics::checkMemory(double usage) {
    std::stringstream result;

    if (usage >= 90.0) {
        result << "WARNING: Memory usage is very high.";
    }
    else if (usage >= 75.0) {
        result << "NOTICE: Memory usage is high.";
    }
    else {
        result << "Memory status: Normal.";
    }

    return result.str();
}

std::string Diagnostics::checkStorage(double usage) {
    std::stringstream result;

    if (usage >= 90.0) {
        result << "WARNING: Storage usage is very high.";
    }
    else if (usage >= 75.0) {
        result << "NOTICE: Storage usage is high.";
    }
    else {
        result << "Storage status: Normal.";
    }

    return result.str();
}
