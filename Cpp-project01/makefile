# Step 1: Tell the Makefile what compiler to use
CXX = g++

# Step 2: Set compiler flags (warnings and optimization)
CXXFLAGS = -Wall -g

# Step 3: Define the name of your final program
TARGET = my_program

# Step 4: The default task (runs when you type just 'make')
all: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Step 5: A task to delete the compiled program to start fresh
clean:
	rm -f $(TARGET)
