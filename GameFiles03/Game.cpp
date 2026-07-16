#include "raylib.h"

struct Player {
    Vector2 pos;
    float speed;
    int size;
};

struct Wall {
    Rectangle rect;
};

struct Block {
    Vector2 pos;
    float speed;
    int size;
};

void ResetBlock(Block &b, int w) {
    b.pos.x = GetRandomValue(0, w);
    b.pos.y = -50;
    b.speed = GetRandomValue(120, 260) / 100.0f;
}

int main() {
    const int screenW = 800;
    const int screenH = 450;

    InitWindow(screenW, screenH, "Triangle Player with Walls");
    SetTargetFPS(60);

    Player p = {{screenW / 2.0f, screenH - 60.0f}, 220.0f, 20};

    Wall walls[] = {
        {{200, 120, 20, 220}},
        {{400, 80, 20, 280}},
        {{600, 150, 20, 220}}
    };
    int wallCount = 3;

    Block b;
    ResetBlock(b, screenW);

    float score = 0;
    bool gameOver = false;

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        if (!gameOver) {

            Vector2 next = p.pos;

            if (IsKeyDown(KEY_LEFT)) next.x -= p.speed * dt;
            if (IsKeyDown(KEY_RIGHT)) next.x += p.speed * dt;

            Rectangle nextRect = {
                next.x - p.size,
                next.y - p.size,
                p.size * 2,
                p.size * 2
            };

            bool blocked = false;

            for (int i = 0; i < wallCount; i++) {
                if (CheckCollisionRecs(nextRect, walls[i].rect)) {
                    blocked = true;
                    break;
                }
            }

            if (!blocked) p.pos = next;

            Rectangle playerRect = {
                p.pos.x - p.size,
                p.pos.y - p.size,
                p.size * 2,
                p.size * 2
            };

            b.pos.y += b.speed * 200 * dt;

            if (b.pos.y > screenH) {
                ResetBlock(b, screenW);
                score += 1;
            }

            Rectangle blockRect = {
                b.pos.x - b.size,
                b.pos.y - b.size,
                b.size * 2,
                b.size * 2
            };

            if (CheckCollisionRecs(playerRect, blockRect)) {
                gameOver = true;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 top = {p.pos.x, p.pos.y - p.size};
        Vector2 left = {p.pos.x - p.size, p.pos.y + p.size};
        Vector2 right = {p.pos.x + p.size, p.pos.y + p.size};

        DrawTriangle(top, left, right, BLUE);

        DrawRectangle(b.pos.x - b.size, b.pos.y - b.size,
                      b.size * 2, b.size * 2, RED);

        for (int i = 0; i < wallCount; i++) {
            DrawRectangleRec(walls[i].rect, DARKGRAY);
        }

        DrawText(TextFormat("Score: %d", (int)score), 10, 10, 20, BLACK);

        if (gameOver) {
            DrawText("GAME OVER", 280, 200, 30, MAROON);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}