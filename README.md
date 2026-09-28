# Kernexis

## C++ Linux-Based System Diagnostics and Resource Monitoring Framework

Kernexis is a C++-based Linux command-line application designed to monitor system resources and provide basic system diagnostics.

The project demonstrates Linux system programming, C++ modular programming, process management, file handling, multithreading, logging and Git-based development.

---

## Features

- System information monitoring
- CPU monitoring
- Memory monitoring
- Running process monitoring
- Storage monitoring
- System diagnostics
- Application logging
- Live resource monitoring
- Multithreading
- Makefile-based build system

---

## Technologies Used

- C++17
- Linux
- WSL2
- GNU Make
- Git
- GitHub

---

## Linux Interfaces Used

Kernexis uses Linux system interfaces including:

- `/proc/cpuinfo`
- `/proc/meminfo`
- `/proc/stat`
- `/proc/uptime`
- `/proc/<PID>/status`
- `/sys`
- `/etc/os-release`

The project also uses Linux APIs such as:

- `uname()`
- `statvfs()`
- Directory and file operations

---

## Project Structure

```text
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
│
├── include/
│   ├── system_info.h
│   ├── cpu_monitor.h
│   ├── memory_monitor.h
│   ├── process_monitor.h
│   ├── storage_monitor.h
│   ├── diagnostics.h
│   ├── logger.h
│   └── live_monitor.h
│
├── tests/
├── logs/
├── docs/
├── Makefile
├── README.md
└── .gitignore
