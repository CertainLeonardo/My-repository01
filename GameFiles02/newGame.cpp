// Simple Raylib Game
// Move the player and collect coins

#include "raylib.h"

struct Player {
    Rectangle rect;
    float speed;
};

struct Coin {
    Vector2 position;
    float radius;
    bool active;
};

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Simple Raylib Game");

    Player player = {
        {100, 100, 40, 40},
        300.0f
    };

    Coin coin = {
        {600, 200},
        15,
        true
    };

    int score = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Movement
        if (IsKeyDown(KEY_W)) player.rect.y -= player.speed * GetFrameTime();
        if (IsKeyDown(KEY_S)) player.rect.y += player.speed * GetFrameTime();
        if (IsKeyDown(KEY_A)) player.rect.x -= player.speed * GetFrameTime();
        if (IsKeyDown(KEY_D)) player.rect.x += player.speed * GetFrameTime();

        // Keep player inside screen
        if (player.rect.x < 0) player.rect.x = 0;
        if (player.rect.y < 0) player.rect.y = 0;
        if (player.rect.x + player.rect.width > screenWidth)
            player.rect.x = screenWidth - player.rect.width;

        if (player.rect.y + player.rect.height > screenHeight)
            player.rect.y = screenHeight - player.rect.height;

        // Coin collision
        if (coin.active &&
            CheckCollisionCircleRec(
                coin.position,
                coin.radius,
                player.rect
            )) {

            score++;
            coin.active = false;
        }

        BeginDrawing();

        ClearBackground(DARKGRAY);

        // Draw player
        DrawRectangleRec(player.rect, SKYBLUE);

        // Draw coin
        if (coin.active) {
            DrawCircleV(coin.position, coin.radius, GOLD);
        }

        // UI
        DrawText("Move with WASD", 10, 10, 20, WHITE);
        DrawText(TextFormat("Score: %i", score), 10, 40, 20, WHITE);

        if (!coin.active) {
            DrawText("You collected the coin!", 250, 200, 30, GREEN);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}