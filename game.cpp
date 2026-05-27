#include "raylib.h"

int main() {
    // 1. Initialize Window
    // Note: If you want true desktop fullscreen, use 0, 0 but pass FLAG_FULLSCREEN_MODE
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(800, 450, "Full Screen Coin Collector");

    // Switch to fullscreen immediately
    ToggleFullscreen();

    // Player variables
    Vector2 playerPos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
    float playerSpeed = 7.0f;
    float playerRadius = 25.0f;

    // Coin variables
    Vector2 coinPos = { 400, 300 };
    float coinRadius = 15.0f;
    int score = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Toggle fullscreen with F
        if (IsKeyPressed(KEY_F)) ToggleFullscreen();

        // 2. Update Movement (Using screen functions inside the loop to account for resizing)
        if (IsKeyDown(KEY_RIGHT) && playerPos.x < GetScreenWidth()) playerPos.x += playerSpeed;
        if (IsKeyDown(KEY_LEFT) && playerPos.x > 0) playerPos.x -= playerSpeed;
        if (IsKeyDown(KEY_UP) && playerPos.y > 0) playerPos.y -= playerSpeed;
        if (IsKeyDown(KEY_DOWN) && playerPos.y < GetScreenHeight()) playerPos.y += playerSpeed;

        // 3. Collision Detection
        if (CheckCollisionCircles(playerPos, playerRadius, coinPos, coinRadius)) {
            score += 10;
            coinPos.x = GetRandomValue(50, GetScreenWidth() - 50);
            coinPos.y = GetRandomValue(50, GetScreenHeight() - 50);
        }

        // 4. Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            DrawText(TextFormat("Score: %i", score), 40, 40, 30, DARKGRAY);
            DrawCircleV(coinPos, coinRadius, GOLD);
            DrawCircleV(playerPos, playerRadius, MAROON);
            
            DrawText("F: Toggle Fullscreen | ESC: Exit", 40, GetScreenHeight() - 60, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
