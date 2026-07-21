#include <raylib.h>
#include <raymath.h> // Required for Vector3 math operations
#include "player.hpp"

int main() {
    InitWindow(1280, 720, "Platformer Game");
    SetTargetFPS(60);

    // Fullscreen toggle
    bool isFullscreen = false;

    // Initialize camera
    Camera3D camera = { 0 };
    camera.position = { 0.0f, 10.0f, 10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Track camera rotation angles
    float cameraAngleH = 0.0f; // Horizontal angle (left/right)
    float cameraAngleV = 0.5f; // Vertical angle (up/down)
    float cameraRadius = 15.0f; // Distance from the player

    // Initialize player
    Player player = { { 0.0f, 0.0f, 0.0f }, 0.1f };

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_F11)) {
            isFullscreen = !isFullscreen;
            ToggleFullscreen();
        }
        // 1. Update Player Movement
        MovePlayer(player, camera);
        camera.target = player.position; // Camera looks at player

        // 2. Handle Mouse Rotation (Right Click)
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Vector2 mouseDelta = GetMouseDelta();
            
            // Adjust angles based on mouse movement speed (0.005f is sensitivity)
            cameraAngleH += mouseDelta.x * 0.005f;
            cameraAngleV += mouseDelta.y * 0.005f;

            // Cap vertical angle so the camera doesn't flip upside down
            if (cameraAngleV > 1.4f) cameraAngleV = 1.4f;
            if (cameraAngleV < 0.1f) cameraAngleV = 0.1f;
        }

        // 3. Calculate New Camera Position around the Player
        camera.position.x = camera.target.x + cameraRadius * cosf(cameraAngleH) * cosf(cameraAngleV);
        camera.position.y = camera.target.y + cameraRadius * sinf(cameraAngleV);
        camera.position.z = camera.target.z + cameraRadius * sinf(cameraAngleH) * cosf(cameraAngleV);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawCube(player.position, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(20, 1.0f); // Ground grid to visualize rotation
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