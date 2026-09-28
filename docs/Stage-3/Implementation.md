# Kernexis - Implementation

## 1. Introduction

Kernexis is implemented as a modular C++ application for Linux system diagnostics and resource monitoring.

The implementation is divided into separate modules for system information, CPU monitoring, memory monitoring, process monitoring, storage monitoring, diagnostics, logging and live monitoring.

## 2. Programming Language

The project is implemented using C++17.

C++ features used include:

- Classes and objects
- Header and source files
- STL containers
- Strings
- File handling
- Exception/error handling concepts
- Multithreading
- Standard library utilities

## 3. System Information Implementation

The System Information module collects:

- Operating system information
- Linux kernel version
- CPU model
- System architecture
- System uptime

Linux interfaces such as `/etc/os-release`, `/proc/cpuinfo`, `/proc/uptime` and `uname()` are used.

## 4. CPU Monitoring

The CPU Monitor collects CPU information and calculates CPU utilization.

The module uses `/proc/cpuinfo` for CPU information and `/proc/stat` for CPU statistics.

CPU usage is calculated by comparing CPU statistics collected at different points in time.

## 5. Memory Monitoring

The Memory Monitor reads memory information from:

`/proc/meminfo`

It calculates:

- Total memory
- Available memory
- Used memory
- Memory utilization percentage

## 6. Process Monitoring

The Process Monitor examines the Linux `/proc` filesystem.

Numeric directories under `/proc` represent process IDs.

For each process, the application reads information from:

`/proc/<PID>/status`

The module displays:

- PID
- Process name
- Process state

## 7. Storage Monitoring

The Storage Monitor uses the Linux `statvfs()` system interface to obtain filesystem statistics.

It calculates:

- Total storage
- Used storage
- Available storage
- Storage utilization percentage

## 8. Diagnostics

The Diagnostics module analyzes CPU, memory and storage utilization.

The module generates status messages such as:

- Normal
- Notice
- Warning

Thresholds are used to identify high resource utilization.

## 9. Logging

The Logger records important application events in:

`logs/kernexis.log`

The logging module supports:

- INFO
- WARNING
- ERROR

Logging helps in debugging and tracking application activity.

## 10. Live Monitoring

The Live Monitoring module provides repeated resource measurements.

C++ `std::thread` is used to execute the monitoring operation in a separate thread.

The monitoring cycle collects:

- CPU usage
- Memory usage
- Storage usage

The values are refreshed periodically.

## 11. Build System

GNU Make is used to simplify compilation.

The Makefile provides commands for:

- Building the project
- Running the application
- Cleaning generated object files and executables

The main commands are:

```bash
make
make run
make clean
