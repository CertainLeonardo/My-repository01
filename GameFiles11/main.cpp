#include <raylib.h>
#include "player.hpp" // Includes your custom header

int main() {
    InitWindow(1280, 720, "Platformer Game");
    SetTargetFPS(60);

    // Initialize camera
    Camera3D camera = { 0 };
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Initialize player
    Player player = { { 0.0f, 0.0f, 0.0f }, 0.1f };

    while (!WindowShouldClose()) {
        // Update
        MovePlayer(player);
        camera.target = player.position; // Camera follows player

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawCube(player.position, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(10, 1.0f); // Helpful floor grid
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

/* Note: Make sure to update your Makefile to include player.cpp
 in the compilation command if you haven't done so already.
 this is necessary because MovePlayer is defined in player.cpp,
 and the compiler needs to know about it when building the final
 executable. 
 .*/