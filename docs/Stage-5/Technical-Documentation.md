# Kernexis - Technical Documentation

## 1. Project Overview

Kernexis is a C++ based Linux System Diagnostics and Resource Monitoring Framework.
It provides system information, CPU monitoring, memory monitoring, process monitoring,
storage monitoring, diagnostics, logging and live resource monitoring.

## 2. Technology Stack

- C++
- Linux / WSL2
- GNU Compiler Collection (G++)
- GNU Make
- Git and GitHub
- Linux /proc and system interfaces

## 3. System Architecture

The application follows a modular architecture.

C++ Application
       |
       v
Monitoring Modules
       |
       +-- System Information
       +-- CPU Monitor
       +-- Memory Monitor
       +-- Process Monitor
       +-- Storage Monitor
       +-- Diagnostics
       +-- Live Monitor
       +-- Logger
       |
       v
Linux System Interfaces
       |
       v
System Resources

## 4. Module Description

### System Information
Collects operating system, kernel, CPU, architecture and uptime information.

### CPU Monitor
Displays CPU core count, logical threads and CPU utilization.

### Memory Monitor
Displays total, available and used memory along with memory utilization.

### Process Monitor
Reads running process information and displays process IDs, names and states.

### Storage Monitor
Displays total, used and available storage information.

### Diagnostics
Evaluates CPU, memory and storage utilization and reports their status.

### Logger
Stores important application events in the project log file.

### Live Monitor
Periodically displays CPU, memory and storage utilization.

## 5. Build System

The project uses a Makefile to simplify compilation and execution.

Main commands:

    make clean
    make
    make run

## 6. Error Handling

The application handles invalid menu choices and reports invalid selections
without terminating the application.

## 7. Testing

The project contains functional, build, logging, live monitoring and invalid
input test cases documented in the Stage 4 testing report.

## 8. Version Control

Git is used for version control and GitHub is used as the remote repository.

Development is organized into stages with meaningful commits.

## 9. Future Enhancements

- Improved input validation
- More detailed process statistics
- Configurable monitoring intervals
- Additional diagnostic rules
- Extended Linux system information
- Optional performance reports

## 10. Conclusion

Kernexis demonstrates the practical application of C++, Linux system programming,
operating-system concepts and resource monitoring through a modular command-line
framework.
