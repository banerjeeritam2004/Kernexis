CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = kernexis

SRC = src/main.cpp \
      src/system_info.cpp \
      src/cpu_monitor.cpp \
      src/memory_monitor.cpp \
      src/process_monitor.cpp \
      src/storage_monitor.cpp \
      src/diagnostics.cpp \
      src/logger.cpp \
      src/live_monitor.cpp

OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)
