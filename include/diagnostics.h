#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <string>

class Diagnostics {
public:
    std::string checkCPU(double usage);
    std::string checkMemory(double usage);
    std::string checkStorage(double usage);
};

#endif
