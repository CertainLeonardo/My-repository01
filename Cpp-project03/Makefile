CXX = clang++

CXXFLAGS = -Iinclude

LDFLAGS = #-lglfw3 -lgdi32 -lopengl32

TARGET = build/main.exe

SRC = src/main.cpp

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: run
run:
	$(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)