# Step 1: Tell the Makefile what compiler to use
CXX = clang++

# Step 2: Set compiler flags (warnings and optimization)
CXXFLAGS = -g -std=c++23 -O2

INCLUDE = -Iinclude

# Step 3: Define the name of your final program
TARGET = build/main.exe

# Step 4: Specify the source files for your project
SRC = src/main.cpp src/example.cpp

.PHONY: build

# this is a build command that compiles the source files specified in the SRC variable into an executable file specified by the TARGET variable, using the compiler and flags defined earlier
build: $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SRC)

.PHONY: run

# this command runs the compiled program specified by the TARGET variable, allowing you to execute your C++ project after building it
run: $(TARGET)
	./$(TARGET)

# Step 5: A task to delete the compiled program to start fresh
.PHONY: clean

# this command removes the compiled executable file specified by the TARGET variable, allowing for a clean build environment
clean:
	rm -f $(TARGET)
