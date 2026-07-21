CXX = g++

CXXFLAGS = -Iinclude

LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

TARGET = build/game.exe

SRC = src/main.cpp \
      src/player.cpp

game: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET)