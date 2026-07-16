CXX = g++
CXXFLAGS = -Wall -std=c++17

# Use your variables so CXXFLAGS actually get applied
game: game.cpp
	$(CXX) $(CXXFLAGS) game.cpp -o 2DGame.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

# Tell Make that 'clean' is a command, not a file name
.PHONY: clean
clean:
	del /Q /F 2DGame.exe 2>nul || exit 0
