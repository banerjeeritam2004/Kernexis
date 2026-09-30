# Kernexis - Final Project Report

## 1. Project Overview

Kernexis is a C++-based Linux System Diagnostics and Resource Monitoring Framework developed as a command-line application.

The main purpose of Kernexis is to collect, monitor, and display important information about a Linux system through a single lightweight application. The framework provides information about the operating system, kernel, CPU, memory, running processes, and storage resources.

The project also includes basic system diagnostics, application logging, file handling, and live resource monitoring using multithreading.

Kernexis was developed to practically implement concepts related to Linux, C++, system programming, operating systems, computer architecture, file handling, process management, multithreading, testing, and Git-based version control.
## 2. Problem Statement

Linux provides several system interfaces and utilities for obtaining information about system resources. However, CPU usage, memory utilization, running processes, storage usage, and system status are generally accessed through different commands or interfaces.

This makes it difficult to view important resource information and basic diagnostic results through a single lightweight application.

Kernexis addresses this problem by providing a unified C++ command-line framework that collects system information, monitors major system resources, performs basic diagnostics, maintains application logs, and provides live monitoring of resource utilization.
## 3. Objectives

The main objectives of Kernexis are:

1. To develop a Linux-based system monitoring application using C++.
2. To collect operating system and kernel information.
3. To monitor CPU utilization and processor information.
4. To monitor memory usage and availability.
5. To display information about running processes.
6. To monitor storage utilization.
7. To provide basic system diagnostics based on resource utilization.
8. To implement application logging using file handling.
9. To implement live monitoring using multithreading.
10. To apply Linux system programming concepts in a practical project.
11. To follow modular software design and proper Git version control.
12. To test and document the developed system.## 4. Project Scope

Kernexis focuses on software-based Linux system monitoring and diagnostics.

### Included Scope

- Operating system information
- Kernel information
- CPU information
- CPU utilization
- Memory utilization
- Process monitoring
- Storage monitoring
- Basic diagnostics
- File handling and logging
- Live monitoring
- Multithreading
- Error handling
- Command-line interface
- Git and GitHub version control
- Testing and technical documentation

### Out of Scope

The current version does not include:

- Graphical user interface
- Cloud deployment
- Database integration
- Physical sensors
- Complex network monitoring
- Advanced kernel-driver development
- AI/ML-based prediction

These features can be considered for future versions.
## 5. System Architecture

The overall architecture of Kernexis follows a modular layered approach.

```text
User
 |
 v
Kernexis Command-Line Interface
 |
 v
Monitoring and Diagnostic Modules
 |
 v
Linux System Interfaces / APIs
 |
 v
Linux Kernel
 |
 v
System Resources
```
## 6. Technologies and Tools Used

### Programming Language

- C++

### Programming Standard

- C++17

### Operating System

- Ubuntu Linux

### Development Environment

- Ubuntu running through WSL2

### Compiler

- GNU G++

### Build Tool

- GNU Make

### Version Control

- Git and GitHub

### Linux Interfaces and APIs

- `/proc`
- `/sys`
- `/etc/os-release`
- `uname()`
- `statvfs()`

### C++ Concepts Used

- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Strings and Vectors
- STL
- File Handling
- Multithreading
- Error Handling
- Modular Programming## 7. Implementation

Kernexis is divided into multiple modules, with each module responsible for a specific system monitoring or diagnostic task.

### 7.1 System Information Module

The System Information Module collects basic information about the Linux system.

It provides:

- Operating system information
- Kernel version
- CPU information
- System architecture
- System uptime

The module uses Linux interfaces such as `/etc/os-release` and `/proc/cpuinfo`. The `uname()` system call is also used to obtain kernel and architecture information.

### 7.2 CPU Monitor

The CPU Monitor provides processor-related information.

It displays:

- CPU core count
- Logical thread count
- CPU utilization

CPU utilization is calculated using CPU statistics obtained from `/proc/stat`.

The application takes CPU statistics at two different points in time and calculates utilization based on the difference between the readings.

### 7.3 Memory Monitor

The Memory Monitor collects memory-related information from `/proc/meminfo`.

It provides:

- Total memory
- Available memory
- Used memory
- Memory utilization percentage

### 7.4 Process Monitor

The Process Monitor reads process information from the Linux `/proc` filesystem.

Linux represents processes using numeric directories inside `/proc`.

Examples:

```text
/proc/1
/proc/2
/proc/100
The module identifies numeric directories as process IDs and reads information from files such as:

```text
/proc/<PID>/status
```
### 7.5 Storage Monitor

The Storage Monitor provides information about the storage capacity and utilization of the Linux filesystem.

It uses the Linux `statvfs()` API to obtain filesystem information.

The module provides:

- Total storage
- Used storage
- Available storage
- Storage utilization percentage

The current implementation monitors the root filesystem and displays the storage information in a readable format.

The Storage Monitor helps the user understand how much storage space is currently being used and how much space is available on the system.
### 7.6 Diagnostics Module

The Diagnostics Module evaluates the current CPU, memory, and storage utilization of the system.

It compares the resource utilization values with predefined thresholds and provides a basic status message.

The diagnostic status is categorized as follows:

```text
Utilization < 75%       -> Normal
75% - 89%               -> Notice
90% or above            -> Warning

### 7.7 Logger Module

The Logger Module is responsible for recording important application events and monitoring activities.

The module uses C++ file handling to write log messages into a log file.

The logger records different types of events such as:

- Application startup
- Module execution
- Monitoring completion
- Warning messages
- Application completion

The log file is maintained at:

```text
logs/kernexis.log
### 7.8 Live Monitoring Module

The Live Monitoring Module provides periodic monitoring of important system resources.

It uses C++ `std::thread` to perform the monitoring process in a separate thread.

The module periodically collects and displays:

- CPU utilization
- Memory utilization
- Storage utilization

The current implementation performs multiple monitoring cycles with a fixed time interval between each cycle.

The Live Monitoring Module demonstrates the practical use of multithreading and periodic resource monitoring in a Linux-based application.
## 8. Command-Line Interface

Kernexis provides an interactive command-line interface through which the user can access different system monitoring and diagnostic functions.

The main menu provides the following options:

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
## 9. Project Structure

The Kernexis project follows a modular directory structure. The source code, header files, testing files, logs, and documentation are maintained separately.

```text
Kernexis/
|
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
|
├── include/
│   ├── system_info.h
│   ├── cpu_monitor.h
│   ├── memory_monitor.h
│   ├── process_monitor.h
│   ├── storage_monitor.h
│   ├── diagnostics.h
│   ├── logger.h
│   └── live_monitor.h
|
├── tests/
│   └── Test-Cases.md
|
├── logs/
│   └── kernexis.log
|
├── docs/
│   ├── Stage-1/
│   ├── Stage-2/
│   ├── Stage-3/
│   ├── Stage-4-Test-Report.md
│   ├── Stage-5/
│   └── Stage-6/
|
├── Makefile
├── README.md
└── .gitignore
## 10. Build and Execution

Kernexis uses a Makefile to simplify the compilation and execution process.

### 10.1 Clean Previous Build

The following command removes previously generated object files and the executable:

```bash
make clean
### 10.2 Compile the Project

The project can be compiled using:

```bash
make
### 10.3 Run the Application

The application can be executed using:

```bash
make run
## 11. Testing and Validation

Testing was performed to verify the functionality, correctness, and reliability of the Kernexis application.

The project was tested at different levels, including build testing, functional testing, input validation, logging validation, and live monitoring validation.

### 11.1 Build Testing

The following commands were tested:

```bash
make clean
make
make run
### 11.2 Functional Testing

Each major menu option was executed individually and its output was verified.

The following modules were tested:

- System Information
- CPU Monitoring
- Memory Monitoring
- Process Monitoring
- Storage Monitoring
- System Diagnostics
- Live Monitoring


### 11.3 Input Validation

Invalid numeric inputs were tested using values such as:

```text
9
0
-1
### 11.4 Logging Testing

The application log was checked to verify that important execution events were recorded in:

```text
logs/kernexis.log
### 11.5 Live Monitoring Testing

The Live Monitoring option was executed to verify periodic CPU, memory, and storage updates.

The monitoring output was displayed successfully for multiple monitoring cycles.

The test confirmed that the monitoring thread was able to collect and display updated resource utilization values at regular intervals.
### 11.6 Test Result

The implemented modules and major application functions were tested successfully during the validation phase.

The testing process confirmed that the Kernexis application can compile, execute, collect system information, monitor system resources, handle invalid numeric inputs, generate log entries, and perform live monitoring as expected.
## 12. Error Handling

Basic error handling has been incorporated throughout the Kernexis application to improve reliability and prevent unexpected termination during normal operation.

The application handles common situations such as:

- Failure to open required Linux system files
- Unavailable system information
- Invalid menu choices
- Unavailable filesystem information
- Missing or unreadable process information

When required information cannot be retrieved, the application uses safe handling mechanisms and continues execution where possible.

Input validation is also implemented for the command-line menu so that invalid numeric choices do not terminate the application.

The error handling approach helps make Kernexis more stable and user-friendly.
## 13. Logging and Monitoring Flow

The general monitoring flow of Kernexis can be represented as follows:

```text
User
 |
 v
Select Monitoring Option
 |
 v
Kernexis Module
 |
 v
Read Linux System Information
 |
 v
Process / Calculate Data
 |
 v
Display Result
 |
 v
Record Important Event in Log
## 14. Hardware and Software Interaction

Although Kernexis is a software-only project, it demonstrates how software interacts with hardware resources through the Linux operating system.

The general interaction can be represented as:

```text
C++ Application
       |
       v
Linux System Interfaces
       |
       v
Linux Kernel
       |
       v
Hardware Resources
       |
       v
CPU / Memory / Storage
## 15. Version Control and GitHub

Git was used throughout the development of Kernexis to maintain the project's version history and track important changes.

The project was developed in multiple stages, and major changes were committed separately.

The major development stages include:

```text
Stage 1 -> Project Introduction
Stage 2 -> Requirements and System Design
Stage 3 -> Implementation
Stage 4 -> Testing and Validation
Stage 5 -> Technical Documentation
Stage 6 -> Final Project Report
## 16. Security Considerations

Kernexis is designed as a read-oriented Linux system monitoring application. The application primarily reads system information and does not intentionally modify critical operating system resources.

The following security considerations were followed during development:

- Avoiding unnecessary privileged operations
- Using read-oriented Linux system interfaces where possible
- Validating user input
- Avoiding unsafe system commands
- Keeping the application modular
- Maintaining logs for application activity

The application does not require administrative privileges for its normal monitoring operations.

Future versions can introduce additional security controls, permission management, and stronger input validation mechanisms.

## 17. Limitations

The current version of Kernexis has some limitations:

1. It is a command-line application and does not provide a graphical user interface.
2. Storage monitoring currently focuses on the root filesystem.
3. Process monitoring displays a limited number of processes.
4. Live monitoring uses a fixed number of monitoring cycles.
5. The current menu primarily validates numeric input.
6. The application does not provide remote system monitoring.
7. It does not provide advanced performance analytics.
8. It does not implement a full Linux kernel device driver.

These limitations can be addressed through future enhancements and additional development.

## 18. Future Enhancements

Kernexis can be extended with additional features to improve its monitoring and diagnostic capabilities.

Possible future enhancements include:

1. Developing a graphical user interface for better visualization.
2. Adding configurable monitoring intervals.
3. Monitoring multiple filesystems instead of only the root filesystem.
4. Adding more detailed process information.
5. Adding CPU temperature and hardware sensor monitoring where supported.
6. Adding network resource monitoring.
7. Adding configurable resource utilization alerts.
8. Exporting monitoring data to CSV or JSON files.
9. Adding historical resource usage graphs.
10. Adding automated system performance reports.
11. Implementing a lightweight Linux kernel-module demonstration.
12. Adding configuration files for user-defined monitoring settings.
13. Adding more advanced Linux system interfaces.

These enhancements can make Kernexis more flexible and suitable for advanced system monitoring and diagnostic requirements.
## 19. Expected Outcome

The expected outcome of Kernexis is a functional Linux-based command-line framework capable of providing important system information and basic resource diagnostics through a unified application.

The project demonstrates practical understanding of:

- C++ programming
- Object-Oriented Programming
- Linux operating system concepts
- Linux system interfaces
- File handling
- Process management
- Multithreading
- CPU and memory monitoring
- Storage monitoring
- Error handling
- Logging
- Software testing
- Git and GitHub
- Technical documentation

The project provides a structured foundation for future development of advanced Linux system monitoring and diagnostic features.
## 20. Conclusion

Kernexis is a Linux-based system diagnostics and resource monitoring framework developed using C++ and Linux system interfaces.

The project combines concepts from Linux, system programming, C++, Object-Oriented Programming, computer architecture, process management, file handling, multithreading, logging, testing, and Git-based version control.

The framework provides a unified command-line interface for viewing system information, monitoring CPU and memory usage, inspecting processes, checking storage utilization, performing basic diagnostics, recording logs, and running live monitoring.

The project also demonstrates how a user-level application can interact with operating system resources through Linux-provided interfaces such as `/proc`, system calls, and filesystem interfaces.

Through the development of Kernexis, practical knowledge of software development, Linux programming, debugging, testing, documentation, and version control was applied in an integrated project.

The project provides a strong foundation for future extensions such as graphical monitoring, network monitoring, advanced diagnostics, hardware sensor integration, and lightweight kernel-level demonstrations.
