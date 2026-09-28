#include "../include/logger.h"

#include <fstream>
#include <iostream>

void Logger::info(const std::string& message) {
    std::ofstream file("logs/kernexis.log", std::ios::app);

    if (file.is_open()) {
        file << "[INFO] " << message << '\n';
    }

    std::cout << "[INFO] " << message << '\n';
}

void Logger::warning(const std::string& message) {
    std::ofstream file("logs/kernexis.log", std::ios::app);

    if (file.is_open()) {
        file << "[WARNING] " << message << '\n';
    }

    std::cout << "[WARNING] " << message << '\n';
}

void Logger::error(const std::string& message) {
    std::ofstream file("logs/kernexis.log", std::ios::app);

    if (file.is_open()) {
        file << "[ERROR] " << message << '\n';
    }

    std::cout << "[ERROR] " << message << '\n';
}
