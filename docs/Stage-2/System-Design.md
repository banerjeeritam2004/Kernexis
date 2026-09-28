# Kernexis - System Design

## 1. System Overview

Kernexis follows a modular architecture. Each module is responsible for monitoring or analyzing a specific part of the Linux system.

The application collects information through Linux system interfaces and presents the processed information through a command-line interface.

## 2. High-Level Architecture

```text
+----------------------+
|        User          |
+----------+-----------+
           |
           v
+----------------------+
|     Kernexis CLI     |
|      Main Module     |
+----------+-----------+
           |
     +-----+-----+
     |     |     |
     v     v     v
 System  Monitor Diagnostics
  Info   Modules    Module
          |
   +------+------+------+
   |      |      |      |
   v      v      v      v
  CPU   Memory Process Storage
   |      |      |      |
   +------+------+------+
          |
          v
+----------------------+
| Linux System         |
| /proc /sys / Calls   |
+----------+-----------+
           |
           v
+----------------------+
| System Resources     |
| CPU RAM Process Disk |
+----------------------+
