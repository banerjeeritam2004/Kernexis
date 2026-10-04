Kernexis — Linux System Diagnostics and Resource Monitoring Framework

A C++17 Linux-Based System Diagnostics and Resource Monitoring Framework

Developer: Ritam Banerjee
Registration Number: 2341002021
Branch: Computer Science and Engineering
GitHub Repository: "Kernexis" (https://github.com/banerjeeritam2004/Kernexis)

---

1. Project Overview

Kernexis is a C++-based system diagnostics and resource monitoring framework developed for Linux environments. It provides a command-line interface for collecting and displaying system information, monitoring CPU and memory usage, inspecting running processes, checking storage capacity, and identifying high resource utilization.

The framework uses Linux system interfaces such as the "/proc" virtual filesystem, system calls, and filesystem statistics to collect system data. It also provides threshold-based diagnostics, file-based logging, and periodic live monitoring.

The project demonstrates Linux system programming, modular C++ development, file handling, multithreading, error handling, testing, and version control.

2. Problem Statement

Linux system information is available through multiple system interfaces and utilities. Manually checking CPU information, memory usage, running processes, and storage capacity can require repeated commands and separate outputs.

Kernexis addresses this problem by bringing common system inspection and basic diagnostic operations into a single menu-driven command-line application.

3. Objectives

- Retrieve operating-system and kernel information.
- Display CPU information and estimate CPU utilization.
- Monitor memory statistics.
- Inspect running processes using Linux process information.
- Check filesystem storage capacity.
- Identify elevated resource utilization through threshold-based diagnostics.
- Record application events and diagnostic messages in a log file.
- Provide periodic live monitoring.
- Apply modular programming, build automation, testing, and Git-based version control.

4. Features

System Information

- Retrieves operating-system information from "/etc/os-release".
- Uses "uname()" to obtain kernel and machine information.
- Reads CPU details from "/proc/cpuinfo".
- Retrieves system uptime from "/proc/uptime".

CPU Monitoring

- Displays processor information.
- Uses Linux CPU counters from "/proc/stat".
- Estimates CPU utilization by comparing readings taken at different times.
- Uses "std::thread::hardware_concurrency()" as an additional logical-processor hint.

Memory Monitoring

- Reads memory statistics from "/proc/meminfo".
- Reports total, available, and related memory values.
- Supports calculation of approximate memory utilization.

Process Monitoring

- Inspects numeric process directories under "/proc".
- Reads process information from "/proc/<PID>/status".
- Displays available process metadata, such as process IDs and status information.

Storage Monitoring

- Uses the "statvfs()" system interface to inspect filesystem capacity.
- Reports total, used, and available storage for the selected filesystem.

System Diagnostics

- Evaluates resource utilization using threshold-based rules.
- Generates a notice when utilization reaches or exceeds 75%.
- Generates a warning when utilization reaches or exceeds 90%.

These thresholds are basic diagnostic rules, not a predictive health model.

Logging

- Records application events in "logs/kernexis.log".
- Uses severity labels such as "INFO", "WARNING", and "ERROR".
- Supports basic troubleshooting and review of recorded events.

Live Monitoring

- Collects repeated resource snapshots.
- Uses C++ threading concepts.
- The documented monitoring workflow performs five cycles with a two-second interval.

Interactive Command-Line Interface

The application provides a menu for selecting individual modules:

1. System Information
2. CPU Monitoring
3. Memory Monitoring
4. Process Monitoring
5. Storage Monitoring
6. System Diagnostics
7. Live Monitoring
8. Exit

5. Technologies and Tools

Technology| Purpose
C++17| Core application development
Linux| Operating-system environment
"/proc"| Access to kernel-provided system and process information
"uname()"| Kernel and machine information
"statvfs()"| Filesystem capacity information
"std::thread"| Basic concurrent execution
GNU g++| C++ compilation
GNU Make| Build automation
Git| Version control
GitHub| Source-code hosting and project submission
Markdown| Project documentation

The project is designed to run in a Linux environment, including Ubuntu through WSL2.

6. System Architecture

The application follows a modular architecture:

                 User
                  |
                  v
          Interactive CLI
                  |
                  v
          C++ Application
                  |
        +---------+---------+
        |         |         |
        v         v         v
      CPU      Memory    Processes
    Monitor    Monitor    Monitor
        |         |         |
        +---------+---------+
                  |
          Linux Interfaces
       /proc, uname(), statvfs()
                  |
                  v
        Linux Kernel and
        System Resources
                  |
                  v
       Terminal Output,
       Diagnostics and Logs

The application reads information exposed by Linux interfaces, processes it in C++, and presents the results through the command-line interface.

7. Project Structure

Kernexis/
├── src/
│   ├── main.cpp
│   ├── system_info.cpp
│   ├── cpu_monitor.cpp
│   ├── memory_monitor.cpp
│   ├── process_monitor.cpp
│   ├── storage_monitor.cpp
│   ├── diagnostics.cpp
│   ├── logger.cpp
│   └── live_monitor.cpp
├── include/
│   ├── system_info.h
│   ├── cpu_monitor.h
│   ├── memory_monitor.h
│   ├── process_monitor.h
│   ├── storage_monitor.h
│   ├── diagnostics.h
│   ├── logger.h
│   └── live_monitor.h
├── tests/
│   └── Test-Cases.md
├── logs/
│   └── kernexis.log
├── docs/
│   ├── Stage-1/
│   │   └── Project-Introduction.md
│   ├── Stage-2/
│   │   ├── Requirements.md
│   │   └── System-Design.md
│   ├── Stage-3/
│   │   └── Implementation.md
│   ├── Stage-4-Test-Report.md
│   ├── Stage-5/
│   │   └── Technical-Documentation.md
│   └── Stage-6/
│       └── Final-Project-Report.md
├── Makefile
├── README.md
└── .gitignore

Note: This structure describes the intended project layout. Keep the README synchronized with the files actually present in the repository.

8. Prerequisites

Before building Kernexis, ensure that the following are available:

- A Linux environment, such as Ubuntu or Ubuntu through WSL2.
- GNU C++ compiler ("g++").
- GNU Make.
- Git, if cloning the repository.

On Ubuntu, install the required tools using:

sudo apt update
sudo apt install build-essential git

Verify the installation:

g++ --version
make --version
git --version

9. Installation

Clone the repository:

git clone https://github.com/banerjeeritam2004/Kernexis.git

Move into the project directory:

cd Kernexis

10. Build and Execution

Clean previous build artifacts:

make clean

Compile the project:

make

Run the executable:

./kernexis

Alternatively, if the "run" target is available in the Makefile:

make run

The interactive menu should appear in the terminal. Select a numbered option to use the corresponding module.

If compilation fails, check that the required source files, header files, compiler, and Makefile are present and consistent.

11. Testing and Validation

The project includes a documented test plan containing 39 test cases across the following categories:

- System information
- CPU monitoring
- Memory monitoring
- Process monitoring
- Storage monitoring
- System diagnostics
- Logging
- Live monitoring
- Build validation
- Invalid menu input

The documented validation workflow includes:

make clean
make
make run

Functional checks verify that the individual modules display their expected information and that diagnostics, logging, and live monitoring operate as intended.

Refer to "tests/Test-Cases.md" and "docs/Stage-4-Test-Report.md" for the test cases and recorded results.

12. Error Handling

Kernexis incorporates basic error-handling practices, including:

- Checking whether system information can be accessed.
- Handling unavailable or unreadable process information.
- Providing messages for invalid numeric menu selections.
- Using compiler warnings during compilation.
- Recording relevant application events through the logging module.

Some Linux process information can change while the application is running. A process may terminate between directory enumeration and file reading, so such cases should be handled without terminating the application unexpectedly.

13. Security Considerations

- The application is designed primarily for reading system information.
- It does not require collecting user passwords or credentials.
- It does not provide remote-control or network-service functionality.
- It should be run with the minimum privileges required.
- Access to some process information may depend on system permissions and configuration.

14. Limitations

- The application uses a command-line interface rather than a graphical interface.
- Available metrics depend on Linux interfaces and the running environment.
- CPU utilization is an estimate based on sampled Linux counters.
- Process information may change while being collected.
- Diagnostics use simple utilization thresholds.
- The current implementation does not include a full hardware-specific Linux kernel device driver.
- The framework is intended as a learning and system-inspection project, not as a replacement for enterprise monitoring tools.

15. Future Enhancements

Potential improvements include:

- Configurable diagnostic thresholds.
- More robust handling of non-numeric input.
- Additional process filters and resource metrics.
- Exporting diagnostic reports to CSV or other formats.
- More comprehensive automated testing.
- Historical resource-usage tracking.
- An optional Linux kernel-module demonstration, if supported by the target kernel environment.

16. Learning Outcomes

This project provides practical experience with:

- C++ modular design and standard library features.
- Linux system interfaces and the "/proc" filesystem.
- Reading and parsing system information.
- Filesystem inspection and process metadata.
- Basic multithreading and periodic monitoring.
- Logging, diagnostics, and error handling.
- Makefile-based compilation.
- Git/GitHub version control.
- Technical documentation and testing.

17. Conclusion

Kernexis demonstrates how C++ and Linux system interfaces can be combined to build a lightweight system diagnostics and resource-monitoring framework. By bringing system information, CPU and memory monitoring, process inspection, storage checks, threshold-based diagnostics, logging, and live monitoring into one command-line application, the project provides a practical demonstration of Linux system programming concepts.

The modular design and accompanying documentation provide a foundation for further improvements in system monitoring and diagnostics.

---

Developer: Ritam Banerjee
Registration Number: 2341002021
Project: Kernexis — A C++ Linux-Based System Diagnostics and Resource Monitoring Framework
Repository: https://github.com/banerjeeritam2004/Kernexis
