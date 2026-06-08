#include "raylib.h"
#include <ctime>

// write a player class 

class Enemy 
{
    public:
        int x, y;
        int radius;
        int health;
        Color color;
        Enemy(int x, int y, int radius, Color color, int health)
        {
            this->x = x;
            this->y = y;
            this->radius = radius;
            this->color = color;
            this->health = health;
        }
        void Draw()
        {
            DrawCircle(x, y, radius, color);
        }
         void MoveTowardsPlayer(int playerX, int playerY)
        {
            if (x < playerX) x += 2;
            if (x > playerX) x -= 2;
            if (y < playerY) y += 2;
            if (y > playerY) y -= 2;
        }
};

class Player 
{
    public:
        int x, y;
        int radius;
        int health;
        Color color;

        Player(int x, int y, int radius, Color color, int health)
        {
            this->x = x;
            this->y = y;
            this->radius = radius;
            this->color = color;
            this->health = health;
        }

        void Draw()
        {
            DrawCircle(x, y, radius, color);
        }
        void Move(int dx, int dy)
        {
            if (IsKeyDown(KEY_W)) y -= 5;
            if (IsKeyDown(KEY_S)) y += 5;
            if (IsKeyDown(KEY_A)) x -= 5;
            if (IsKeyDown(KEY_D)) x += 5;
        }
        void Punch (Enemy &enemy)
        {
            if (CheckCollisionCircles((Vector2){x, y}, radius, (Vector2){enemy.x, enemy.y}, enemy.radius))
            {
                enemy.health -= 10;
            }
        }
        
};

void DrawHealthValue(int health)
{
    DrawText(TextFormat("Health: %d", health), 10, 10, 20, WHITE);
}

void FullscreenToggle()
{
    if (IsKeyPressed(KEY_F))
    {
        ToggleFullscreen();
        float screenWidth = GetScreenWidth();
        float screenHeight = GetScreenHeight();

        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
    }
}

void PauseGame(bool &isPaused)
{
    if (IsKeyPressed(KEY_P))
    {
        isPaused = !isPaused;
        if (isPaused)
        {
            DrawText("Game Paused", 350, 300, 40, YELLOW);
            return;
        }
    }
}

int main()
{
    bool isPaused = false;
    bool gameOver = false;
    bool isFullscreen = false;
    float screenWidth = 800;
    float screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Game");
    
    SetTargetFPS(60);

    Player player(400, 300, 50, RED, 100);
    Enemy enemy(100, 100, 30, BLUE, 50);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        FullscreenToggle();
        PauseGame(isPaused);
        player.Draw();
        player.Move(0, 0);
        DrawHealthValue(player.health);

        enemy.Draw();
        enemy.MoveTowardsPlayer(player.x, player.y);

        if (player.health <= 0.0)
        {
            DrawText("Game Over!", 350, 300, 40, RED);
                
                player.x = 400;
                player.y = 300;
                player.health = 100;
                gameOver = true;
                return 0;
        }

        if (enemy.health > 0)
        {
            DrawText(TextFormat("Enemy Health: %d", enemy.health), 10, 40, 20, WHITE);
        }

        if (CheckCollisionCircles((Vector2){player.x, player.y}, player.radius, (Vector2){enemy.x, enemy.y}, enemy.radius))
        {
            time_t currentTime = GetTime();
            static time_t lastDamageTime = 0;
            if (currentTime - lastDamageTime > 1) // 1 second cooldown
            {
                lastDamageTime = currentTime;
            }
            player.health -= 1;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}