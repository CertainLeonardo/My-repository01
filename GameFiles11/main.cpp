#include <raylib.h>
#include <iostream>

int main() {
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}