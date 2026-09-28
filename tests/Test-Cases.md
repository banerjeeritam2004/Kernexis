# Kernexis - Test Cases

## 1. System Information Test

| Test ID | Test | Expected Result |
|---|---|---|
| TC01 | Run Kernexis | Application starts successfully |
| TC02 | Check OS information | OS information is displayed |
| TC03 | Check kernel version | Kernel version is displayed |
| TC04 | Check CPU information | CPU model is displayed |
| TC05 | Check architecture | System architecture is displayed |
| TC06 | Check uptime | System uptime is displayed |

## 2. CPU Monitoring Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC07 | Check CPU cores | CPU core count is displayed |
| TC08 | Check logical threads | Logical thread count is displayed |
| TC09 | Check CPU usage | CPU usage percentage is displayed |

## 3. Memory Monitoring Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC10 | Check total memory | Total memory is displayed |
| TC11 | Check available memory | Available memory is displayed |
| TC12 | Check used memory | Used memory is displayed |
| TC13 | Check memory usage | Memory usage percentage is displayed |

## 4. Process Monitoring Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC14 | Read running processes | Process list is displayed |
| TC15 | Display PID | Process IDs are displayed |
| TC16 | Display process name | Process names are displayed |
| TC17 | Display process state | Process states are displayed |

## 5. Storage Monitoring Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC18 | Check total storage | Total storage is displayed |
| TC19 | Check used storage | Used storage is displayed |
| TC20 | Check available storage | Available storage is displayed |
| TC21 | Check storage usage | Storage usage percentage is displayed |

## 6. Diagnostics Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC22 | Check CPU status | CPU diagnostic message is displayed |
| TC23 | Check memory status | Memory diagnostic message is displayed |
| TC24 | Check storage status | Storage diagnostic message is displayed |

## 7. Logging Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC25 | Start application | Startup information is logged |
| TC26 | Complete monitoring | Monitoring information is logged |
| TC27 | Check log file | Log entries are available |

## 8. Live Monitoring Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC28 | Start live monitoring | Monitoring starts successfully |
| TC29 | Multiple monitoring cycles | Resource values are refreshed |
| TC30 | CPU usage update | CPU values can change between cycles |
| TC31 | Memory usage update | Memory values are displayed |
| TC32 | Storage usage update | Storage values are displayed |

## 9. Build Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC33 | Run `make clean` | Build files are removed |
| TC34 | Run `make` | Project compiles successfully |
| TC35 | Run `make run` | Application starts successfully |
## 10. Invalid Input Tests

| Test ID | Test | Expected Result |
|---|---|---|
| TC36 | Enter invalid menu choice | Invalid choice message is displayed |
| TC37 | Enter choice greater than 8 | Application handles invalid input safely |
| TC38 | Enter zero as choice | Invalid choice message is displayed |
| TC39 | Enter negative choice | Invalid choice message is displayed |

## 11. Test Summary

| Category | Test Cases |
|---|---:|
| System Information | 6 |
| CPU Monitoring | 3 |
| Memory Monitoring | 4 |
| Process Monitoring | 4 |
| Storage Monitoring | 4 |
| Diagnostics | 3 |
| Logging | 3 |
| Live Monitoring | 5 |
| Build Testing | 3 |
| Invalid Input | 4 |
| **Total** | **39** |

## 12. Testing Conclusion

The Kernexis application was tested module-by-module using functional, build, logging, live monitoring, and invalid input test cases. The tests verify that the major monitoring modules execute correctly, display system resource information, handle invalid menu choices, and build successfully using the project Makefile.
