#include "raylib.h"

int main() {
    InitWindow(1920, 1080, "Raylib Basics");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib", 300, 200, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}