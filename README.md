# Kernexis

## A C++ Linux-Based System Diagnostics and Resource Monitoring Framework

Kernexis is a C++17-based Linux command-line framework designed to monitor system resources and provide basic system diagnostics.

The project collects system-level information using Linux interfaces such as `/proc`, `/etc/os-release`, and Linux system APIs. It provides CPU, memory, process, and storage monitoring along with threshold-based diagnostics, logging, and live resource monitoring.

---

## Project Overview

Modern operating systems continuously manage CPU, memory, processes, and storage resources. Understanding these resources is important for identifying high resource utilization and basic system-performance issues.

Kernexis provides a single command-line interface through which users can access different system-monitoring modules.

The project demonstrates:

- Linux system programming
- C++ modular programming
- Linux `/proc` filesystem
- File handling
- Process monitoring
- CPU and memory monitoring
- Storage monitoring
- Multithreading
- Logging
- Error handling
- Makefile-based compilation
- Git and GitHub-based development

---

## Objectives

The main objectives of Kernexis are:

1. To collect and display Linux system information.
2. To monitor CPU utilization and processor information.
3. To monitor memory usage.
4. To inspect running processes.
5. To monitor storage utilization.
6. To perform basic system diagnostics.
7. To provide live resource monitoring.
8. To maintain application logs.
9. To demonstrate modular C++ system programming.
10. To provide a structured and maintainable Linux-based monitoring framework.

---

## Features

### System Information
- Operating system information
- Kernel information
- Machine architecture
- CPU information
- System uptime

### CPU Monitoring
- CPU model information
- Logical processor information
- CPU utilization estimation
- CPU statistics using `/proc/stat`

### Memory Monitoring
- Total memory
- Available memory
- Free memory
- Memory utilization

### Process Monitoring
- Running process identification
- Process ID (PID)
- Process information
- Process status using `/proc/<PID>/status`

### Storage Monitoring
- Total storage capacity
- Used storage
- Available storage
- Filesystem utilization using `statvfs()`

### System Diagnostics
- CPU utilization checks
- Memory utilization checks
- Storage utilization checks
- Warning and notice levels

### Logging
- INFO messages
- WARNING messages
- ERROR messages
- Runtime log stored in `logs/kernexis.log`

### Live Monitoring
- Periodic resource monitoring
- CPU monitoring
- Memory monitoring
- Storage monitoring
- Multithreaded execution using C++ threads

### Interactive CLI
The application provides a menu-driven command-line interface:

```text
========================================
              KERNEXIS
     System Diagnostics Framework
========================================

1. System Information
2. CPU Monitoring
3. Memory Monitoring
4. Process Monitoring
5. Storage Monitoring
6. System Diagnostics
7. Live Monitoring
8. Exit

Enter your choice:


```
## Linux Interfaces Used

Kernexis uses Linux-provided system interfaces to obtain system information.

```text
┌──────────────────────────────────────────────────────────────┐
│                    Linux Interfaces Used                     │
├──────────────────────────────┬───────────────────────────────┤
│ Interface                    │ Purpose                       │
├──────────────────────────────┼───────────────────────────────┤
│ /proc/cpuinfo                │ CPU and processor information │
│ /proc/stat                   │ CPU utilization statistics   │
│ /proc/meminfo                │ Memory information            │
│ /proc/uptime                 │ System uptime                 │
│ /proc/<PID>/status           │ Process information           │
│ /etc/os-release              │ Operating system information │
│ uname()                      │ Kernel and machine details   │
│ statvfs()                    │ Filesystem storage statistics│
└──────────────────────────────┴───────────────────────────────┘

```
## System Architecture

Kernexis follows a modular architecture in which the C++ application collects
system information through Linux interfaces and processes the collected data.

┌──────────────────────────────────────────────────────────────┐
│                         USER                                 │
│                  Command-Line Interface                      │
└─────────────────────────────┬────────────────────────────────┘
                              │
                              ▼
┌──────────────────────────────────────────────────────────────┐
│                    KERNEXIS C++ APPLICATION                  │
│                         main.cpp                             │
└─────────────────────────────┬────────────────────────────────┘
                              │
          ┌───────────────────┼───────────────────┐
          ▼                   ▼                   ▼
┌─────────────────┐  ┌─────────────────┐  ┌─────────────────┐
│ System Info     │  │ CPU Monitor     │  │ Memory Monitor  │
│ Module          │  │ Module          │  │ Module          │
└────────┬────────┘  └────────┬────────┘  └────────┬────────┘
         │                    │                    │
         └────────────────────┼────────────────────┘
                              ▼
┌──────────────────────────────────────────────────────────────┐
│                    LINUX SYSTEM INTERFACES                   │
│                                                              │
│  /proc/cpuinfo   /proc/stat   /proc/meminfo   /proc/uptime │
│  /proc/<PID>/status   /etc/os-release   uname()   statvfs()│
└─────────────────────────────┬────────────────────────────────┘
                              │
                              ▼
┌──────────────────────────────────────────────────────────────┐
│                     SYSTEM RESOURCES                         │
│                                                              │
│             CPU  │  MEMORY  │  PROCESSES  │  STORAGE        │
└─────────────────────────────┬────────────────────────────────┘
                              │
                              ▼
┌──────────────────────────────────────────────────────────────┐
│              DIAGNOSTICS + LOGGING + LIVE MONITORING         │
└──────────────────────────────────────────────────────────────┘

## Core Modules

┌──────────────────────────────────────────────────────────────┐
│                     KERNEXIS MODULES                         │
├──────────────────────────┬───────────────────────────────────┤
│ Module                   │ Main Responsibility               │
├──────────────────────────┼───────────────────────────────────┤
│ System Information       │ OS, kernel, CPU and uptime data  │
│ CPU Monitor              │ CPU details and utilization      │
│ Memory Monitor           │ Memory usage statistics           │
│ Process Monitor          │ Running process information      │
│ Storage Monitor          │ Filesystem storage utilization   │
│ Diagnostics              │ Resource usage analysis          │
│ Logger                   │ Runtime event logging             │
│ Live Monitor             │ Periodic resource monitoring     │
│ CLI / main.cpp           │ User interaction and menu        │
└──────────────────────────┴───────────────────────────────────┘

## Project Structure

┌──────────────────────────────────────────────────────────────┐
│                         KERNEXIS                             │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  src/                                                        │
│  ├── main.cpp                 → Main CLI and program flow   │
│  ├── system_info.cpp         → System information           │
│  ├── cpu_monitor.cpp         → CPU monitoring               │
│  ├── memory_monitor.cpp      → Memory monitoring            │
│  ├── process_monitor.cpp     → Process monitoring           │
│  ├── storage_monitor.cpp     → Storage monitoring           │
│  ├── diagnostics.cpp         → System diagnostics           │
│  ├── logger.cpp              → Logging functionality         │
│  └── live_monitor.cpp        → Live monitoring               │
│                                                              │
│  include/                                                     │
│  └── *.h                       → Module header files         │
│                                                              │
│  tests/                                                        │
│  └── Test-Cases.md             → Test cases and validation   │
│                                                              │
│  logs/                                                         │
│  └── kernexis.log              → Runtime log file            │
│                                                              │
│  docs/                                                         │
│  ├── Stage-1/                  → Project introduction        │
│  ├── Stage-2/                  → Requirements & design       │
│  ├── Stage-3/                  → Implementation              │
│  ├── Stage-4-Test-Report.md    → Testing report              │
│  ├── Stage-5/                  → Technical documentation     │
│  └── Stage-6/                  → Final project report         │
│                                                              │
│  Makefile                     → Build automation             │
│  README.md                    → Project documentation         │
│  .gitignore                   → Ignored files                 │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Technologies Used

┌──────────────────────────┬───────────────────────────────────┐
│ Technology / Tool        │ Purpose                           │
├──────────────────────────┼───────────────────────────────────┤
│ C++17                    │ Core application development     │
│ Linux / Ubuntu           │ Operating system environment     │
│ Linux /proc              │ System and process information   │
│ STL                      │ C++ data structures & utilities  │
│ std::thread              │ Live monitoring / multithreading  │
│ GNU Make                 │ Project build automation         │
│ GCC / G++                │ C++ compilation                  │
│ Git                      │ Version control                  │
│ GitHub                   │ Project repository & submission  │
│ VS Code                  │ Source-code development          │
│ WSL2                     │ Linux development environment    │
└──────────────────────────┴───────────────────────────────────┘

## Build Requirements & Installation

┌──────────────────────────────────────────────────────────────┐
│                    SYSTEM REQUIREMENTS                       │
├──────────────────────────┬───────────────────────────────────┤
│ Requirement              │ Details                           │
├──────────────────────────┼───────────────────────────────────┤
│ Operating System         │ Linux / Ubuntu                    │
│ Compiler                 │ GCC / G++ with C++17 support     │
│ Build Tool               │ GNU Make                          │
│ Version Control          │ Git                               │
│ Development Environment  │ WSL2 / Ubuntu                     │
└──────────────────────────┴───────────────────────────────────┘

Installation:

1. Clone the repository:

   git clone https://github.com/banerjeeritam2004/Kernexis.git

2. Enter the project directory:

   cd Kernexis

3. Verify the compiler:

   g++ --version

4. Verify GNU Make:

   make --version

5. Build the project:

   make

## Build and Run

┌──────────────────────────────────────────────────────────────┐
│                       BUILD PROCESS                          │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  Step 1 → Open the Kernexis project directory               │
│                                                              │
│  cd ~/Kernexis                                                │
│                                                              │
│  Step 2 → Build the project                                  │
│                                                              │
│  make                                                         │
│                                                              │
│  Step 3 → Run Kernexis                                       │
│                                                              │
│  ./kernexis                                                    │
│                                                              │
│  Step 4 → Clean generated object files and executable        │
│                                                              │
│  make clean                                                    │
│                                                              │
│  Step 5 → Build again if required                            │
│                                                              │
│  make                                                         │
│                                                              │
└──────────────────────────────────────────────────────────────┘

   ## Features

┌──────────────────────────────────────────────────────────────┐
│                      KERNEXIS FEATURES                       │
├──────────────────────────┬───────────────────────────────────┤
│ Feature                  │ Description                       │
├──────────────────────────┼───────────────────────────────────┤
│ System Information       │ Displays OS, kernel and CPU data │
│ CPU Monitoring           │ Monitors CPU details and usage   │
│ Memory Monitoring        │ Displays memory utilization      │
│ Process Monitoring       │ Shows running process details   │
│ Storage Monitoring       │ Checks filesystem usage          │
│ System Diagnostics       │ Detects high resource usage     │
│ Live Monitoring          │ Provides periodic monitoring    │
│ Logging                  │ Records runtime events          │
│ Error Handling           │ Handles invalid/runtime errors  │
│ Interactive CLI          │ Menu-based user interaction     │
└──────────────────────────┴───────────────────────────────────┘

## Linux System Interfaces

┌──────────────────────────────────────────────────────────────┐
│                  LINUX SYSTEM INTERFACES                     │
├──────────────────────────┬───────────────────────────────────┤
│ Interface                │ Usage                             │
├──────────────────────────┼───────────────────────────────────┤
│ /proc/cpuinfo            │ CPU and processor information    │
│ /proc/stat               │ CPU utilization statistics       │
│ /proc/meminfo            │ Memory usage information         │
│ /proc/uptime             │ System uptime information        │
│ /proc/<PID>/status       │ Individual process information  │
│ /etc/os-release          │ Operating system information     │
│ uname()                  │ Kernel and machine information  │
│ statvfs()                │ Filesystem storage information  │
└──────────────────────────┴───────────────────────────────────┘
## Diagnostics Logic

┌──────────────────────────────────────────────────────────────┐
│                    DIAGNOSTICS LOGIC                         │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  Resource Utilization                                        │
│          │                                                   │
│          ▼                                                   │
│  ┌───────────────────────┐                                   │
│  │ Check Usage Level     │                                   │
│  └───────────┬───────────┘                                   │
│              │                                               │
│       ┌──────┼──────┐                                        │
│       ▼      ▼      ▼                                        │
│     <75%   75-89%   ≥90%                                    │
│       │      │      │                                        │
│       ▼      ▼      ▼                                        │
│     NORMAL  NOTICE  WARNING                                  │
│                                                              │
│  The diagnostic module analyzes CPU, memory, and storage     │
│  utilization and reports the corresponding system status.   │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Logging System

┌──────────────────────────────────────────────────────────────┐
│                       LOGGING SYSTEM                         │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│                    KERNEXIS APPLICATION                      │
│                            │                                 │
│                            ▼                                 │
│                    ┌───────────────┐                         │
│                    │    Logger     │                         │
│                    │    Module     │                         │
│                    └───────┬───────┘                         │
│                            │                                 │
│             ┌──────────────┼──────────────┐                  │
│             ▼              ▼              ▼                  │
│           INFO          WARNING         ERROR                │
│             │              │              │                  │
│             └──────────────┼──────────────┘                  │
│                            ▼                                 │
│                    logs/kernexis.log                         │
│                                                              │
└──────────────────────────────────────────────────────────────┘



## Testing and Validation

┌──────────────────────────────────────────────────────────────┐
│                    TESTING AND VALIDATION                    │
├──────────────────────────┬───────────────────────────────────┤
│ Test Category            │ Result                            │
├──────────────────────────┼───────────────────────────────────┤
│ System Information       │ PASS                              │
│ CPU Monitoring           │ PASS                              │
│ Memory Monitoring        │ PASS                              │
│ Process Monitoring       │ PASS                              │
│ Storage Monitoring       │ PASS                              │
│ System Diagnostics       │ PASS                              │
│ Logging                  │ PASS                              │
│ Live Monitoring          │ PASS                              │
│ Build Testing            │ PASS                              │
│ Invalid Input Handling   │ PASS                              │
├──────────────────────────┼───────────────────────────────────┤
│ Total Test Cases         │ 39                                │
│ Overall Result           │ ALL TESTS PASSED                  │
└──────────────────────────┴───────────────────────────────────┘

## Error Handling

┌──────────────────────────────────────────────────────────────┐
│                      ERROR HANDLING                          │
├──────────────────────────┬───────────────────────────────────┤
│ Error / Condition        │ Handling Method                  │
├──────────────────────────┼───────────────────────────────────┤
│ Invalid menu choice      │ Displays error message           │
│ Invalid numeric input    │ Validates user input             │
│ File access failure      │ Handles file operation errors    │
│ /proc read failure       │ Reports unavailable data         │
│ Logging failure          │ Handles log file errors          │
│ System call failure      │ Checks return values             │
│ Runtime exception        │ Prevents unexpected termination  │
└──────────────────────────┴───────────────────────────────────┘

## Live Monitoring

┌──────────────────────────────────────────────────────────────┐
│                     LIVE MONITORING                          │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│                 KERNEXIS LIVE MONITOR                        │
│                          │                                   │
│                          ▼                                   │
│                ┌──────────────────┐                          │
│                │ Start Monitoring │                          │
│                └────────┬─────────┘                          │
│                         │                                    │
│                         ▼                                    │
│              ┌──────────────────────┐                        │
│              │ Collect System Data  │                        │
│              └──────────┬───────────┘                        │
│                         │                                    │
│             ┌───────────┼───────────┐                        │
│             ▼           ▼           ▼                        │
│           CPU        MEMORY      STORAGE                     │
│             │           │           │                        │
│             └───────────┼───────────┘                        │
│                         ▼                                    │
│                 Display Statistics                            │
│                         │                                    │
│                         ▼                                    │
│                  Wait 2 Seconds                              │
│                         │                                    │
│                         └──────► Repeat                      │
│                                                              │
│  Live monitoring uses C++ std::thread for periodic           │
│  resource monitoring without blocking the main workflow.     │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Multithreading

┌──────────────────────────────────────────────────────────────┐
│                     MULTITHREADING                           │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│                    MAIN PROGRAM                              │
│                         │                                    │
│                         ▼                                    │
│                Live Monitoring Module                        │
│                         │                                    │
│                         ▼                                    │
│                  std::thread                                 │
│                         │                                    │
│              ┌──────────┴──────────┐                         │
│              ▼                     ▼                         │
│       Resource Collection     Monitoring Loop                │
│              │                     │                         │
│              └──────────┬──────────┘                         │
│                         ▼                                    │
│                  System Statistics                            │
│                                                              │
│  The live monitoring module uses C++ std::thread to perform  │
│  periodic resource monitoring independently.                │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Security Considerations

┌──────────────────────────────────────────────────────────────┐
│                  SECURITY CONSIDERATIONS                     │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  • Kernexis performs read-only system monitoring.            │
│                                                              │
│  • No system configuration is modified by the application.  │
│                                                              │
│  • No user passwords or sensitive credentials are collected. │
│                                                              │
│  • System information is accessed through standard Linux    │
│    interfaces such as /proc and system APIs.                 │
│                                                              │
│  • The application is designed to run with normal user      │
│    privileges wherever possible.                             │
│                                                              │
│  • Input validation is used to handle invalid menu choices. │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Limitations

┌──────────────────────────────────────────────────────────────┐
│                       LIMITATIONS                            │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  • Kernexis is currently a command-line based application.  │
│                                                              │
│  • Monitoring depends on Linux system interfaces such as    │
│    /proc and standard system APIs.                           │
│                                                              │
│  • The current version does not provide a graphical user     │
│    interface (GUI).                                          │
│                                                              │
│  • The diagnostic rules use predefined resource thresholds  │
│    and do not perform advanced predictive analysis.          │
│                                                              │
│  • Monitoring is focused on basic CPU, memory, process, and  │
│    storage information.                                      │
│                                                              │
│  • The project does not currently implement a complete       │
│    hardware-specific Linux kernel device driver.             │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Future Enhancements

┌──────────────────────────────────────────────────────────────┐
│                    FUTURE ENHANCEMENTS                       │
├──────────────────────────────────────────────────────────────┤
│                                                              │
│  • Add a graphical user interface for easier monitoring.     │
│                                                              │
│  • Implement advanced Linux kernel/device-driver concepts    │
│    for deeper hardware and kernel interaction.               │
│                                                              │
│  • Add configurable monitoring thresholds.                   │
│                                                              │
│  • Support longer-term resource usage history and reports.   │
│                                                              │
│  • Add more detailed process and system diagnostics.         │
│                                                              │
│  • Improve input validation and command-line usability.      │
│                                                              │
│  • Add automated test execution and continuous integration.  │
│                                                              │
└──────────────────────────────────────────────────────────────┘

## Documentation

┌──────────────────────────────────────────────────────────────┐
│                      DOCUMENTATION                           │
├──────────────────────────┬───────────────────────────────────┤
│ Document                 │ Description                       │
├──────────────────────────┼───────────────────────────────────┤
│ Stage 1                  │ Project Introduction              │
│ Stage 2                  │ Requirements and System Design   │
│ Stage 3                  │ Implementation Details           │
│ Stage 4                  │ Testing and Validation Report    │
│ Stage 5                  │ Technical Documentation          │
│ Stage 6                  │ Final Project Report             │
│ Test-Cases.md            │ Test cases and results           │
│ README.md                │ Project overview and usage       │
└──────────────────────────┴───────────────────────────────────┘

Author / Project Information

Project: Kernexis – A C++ Linux-Based System Diagnostics and Resource Monitoring Framework
Developer: Ritam Banerjee
Registration Number: 2341002021
Technology: C++17, Linux, GNU Make
Repository: https://github.com/banerjeeritam2004/Kernexis

Project Status

Kernexis is a completed academic capstone project focused on Linux-based system diagnostics, resource monitoring, logging, live monitoring, testing, and technical documentation.
