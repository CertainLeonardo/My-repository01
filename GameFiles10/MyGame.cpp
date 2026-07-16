#include <raylib.h>
#include <iostream>
using namespace std;

/* Enter this command for compilation:
    g++ MyGame.cpp -o MyGame -lraylib -lopengl32 -lgdi32 -lwinmm
*/

void InitGame() {
    // Initialization code here
    InitWindow(800, 600, "My Game");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawText("Hello, World!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
}

int main() {
    InitGame();
    return 0;
}