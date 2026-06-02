#include "raylib.h"

struct Player {
    Vector3 pos;
    float speed;
};

struct Pickup {
    Vector3 pos;
    bool active;
};

int main() {
    const int screenW = 800;
    const int screenH = 450;

    InitWindow(screenW, screenH, "Simple 3D Raylib Game");
    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.position = {0.0f, 10.0f, 15.0f};
    camera.target = {0.0f, 0.0f, 0.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Player player;
    player.pos = {0.0f, 1.0f, 0.0f};
    player.speed = 5.0f;

    const int pickupCount = 5;
    Pickup pickups[pickupCount];

    for (int i = 0; i < pickupCount; i++) {
        pickups[i].pos = {
            (float)GetRandomValue(-10, 10),
            1.0f,
            (float)GetRandomValue(-10, 10)
        };
        pickups[i].active = true;
    }

    int score = 0;

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        Vector3 next = player.pos;

        if (IsKeyDown(KEY_W)) next.z -= player.speed * dt;
        if (IsKeyDown(KEY_S)) next.z += player.speed * dt;
        if (IsKeyDown(KEY_A)) next.x -= player.speed * dt;
        if (IsKeyDown(KEY_D)) next.x += player.speed * dt;

        player.pos = next;

        camera.target = player.pos;
        camera.position = {
            player.pos.x,
            player.pos.y + 10.0f,
            player.pos.z + 15.0f
        };

        for (int i = 0; i < pickupCount; i++) {
            if (!pickups[i].active) continue;

            float dx = player.pos.x - pickups[i].pos.x;
            float dz = player.pos.z - pickups[i].pos.z;

            if ((dx * dx + dz * dz) < 1.5f) {
                pickups[i].active = false;
                score += 1;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane({0, 0, 0}, {20, 20}, LIGHTGRAY);

        DrawCube(player.pos, 1.0f, 2.0f, 1.0f, BLUE);

        for (int i = 0; i < pickupCount; i++) {
            if (pickups[i].active) {
                DrawCube(pickups[i].pos, 0.5f, 0.5f, 0.5f, GOLD);
                DrawCubeWires(pickups[i].pos, 0.5f, 0.5f, 0.5f, ORANGE);
            }
        }

        EndMode3D();

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}