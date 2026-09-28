# Kernexis - Requirements Specification

## 1. Introduction

Kernexis is a C++-based Linux System Diagnostics and Resource Monitoring Framework. It is designed as a command-line application for collecting and displaying important system information and resource usage.

The system focuses on CPU, memory, processes, storage and basic diagnostics using Linux system interfaces.

## 2. Problem Statement

Computer systems continuously use resources such as CPU, memory and storage. Users need a simple way to inspect these resources and identify basic resource-related issues.

Kernexis provides a lightweight command-line solution for monitoring and diagnosing these system resources.

## 3. Objectives

- Develop a Linux-based system monitoring application using C++.
- Display important system information.
- Monitor CPU utilization.
- Monitor memory usage.
- Display running process information.
- Monitor storage usage.
- Perform basic system diagnostics.
- Implement application logging.
- Practice Linux system programming concepts.
- Use Git and GitHub for version control.

## 4. Functional Requirements

### 4.1 System Information

The application shall display:

- Operating system information
- Linux kernel version
- CPU model
- Number of CPU cores
- Number of logical processors
- System architecture
- System uptime

### 4.2 CPU Monitoring

The application shall provide:

- CPU model
- Number of cores
- Number of logical processors
- CPU utilization
- CPU statistics

### 4.3 Memory Monitoring

The application shall provide:

- Total memory
- Used memory
- Available memory
- Free memory
- Memory utilization percentage

### 4.4 Process Monitoring

The application shall display information about running processes, including:

- Process ID
- Process name
- Process state
- CPU-related information
- Memory-related information

### 4.5 Storage Monitoring

The application shall display:

- Filesystem
- Total storage
- Used storage
- Available storage
- Storage utilization percentage

### 4.6 Diagnostics

The application shall perform basic checks for:

- High CPU utilization
- High memory utilization
- Low available storage
- Invalid system information
- Unavailable Linux system interfaces

### 4.7 Logging

The application shall maintain logs for:

- Application startup
- Warnings
- Errors
- Diagnostic events
- Application shutdown

### 4.8 Live Monitoring

The application may provide a live monitoring mode that periodically refreshes CPU, memory, process and storage information.

## 5. Non-Functional Requirements

### Performance

The application should consume limited CPU and memory resources.

### Reliability

The application should handle errors without unexpected termination.

### Maintainability

The application should use modular C++ source and header files.

### Usability

The command-line output should be simple and understandable.

### Error Handling

File access errors and invalid system information should be handled properly.

### Portability

The application is primarily designed for Linux-based systems.

### Security

The application should operate without unnecessary administrator privileges.

## 6. Hardware Requirements

- x86_64 compatible computer
- Minimum 4 GB RAM
- Minimum 2 CPU cores
- Minimum 1 GB available storage

## 7. Software Requirements

- Linux / WSL2
- C++ compiler
- GNU Make
- Git
- Linux /proc and /sys interfaces

## 8. Technology Stack

- C++
- Linux
- GNU Make
- Git
- GitHub
- /proc
- /sys
- Linux system calls

## 9. Constraints

- Initial version will use a command-line interface.
- The project primarily targets Linux.
- No physical hardware is required.
- Advanced kernel-driver development is outside the initial scope.
- Normal operation should not require root privileges.

## 10. Expected Output

Kernexis should provide:

- System information
- CPU information and usage
- Memory information and usage
- Process information
- Storage information
- Diagnostic messages
- Logs
- Live monitoring

## 11. Future Scope

Future versions may include:

- Graphical user interface
- Network monitoring
- Configurable alerts
- Advanced diagnostics
- Performance reports
- Data export
- Plugin architecture
- Advanced Linux driver integration

## 12. Conclusion

The requirements define the core functionality and constraints of Kernexis. These requirements will be used as the foundation for the system architecture and implementation stages.
