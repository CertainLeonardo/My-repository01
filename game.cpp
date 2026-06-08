#include "raylib.h"

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
            if (health > 0) DrawCircle(x, y, radius, color);
        }

        void MoveTowardsPlayer(int playerX, int playerY)
        {
            if (health <= 0) return; // Dead enemies don't move
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

        void Move() // Removed unused dx, dy parameters
        {
            if (IsKeyDown(KEY_W)) y -= 5;
            if (IsKeyDown(KEY_S)) y += 5;
            if (IsKeyDown(KEY_A)) x -= 5;
            if (IsKeyDown(KEY_D)) x += 5;
        }

        void Punch(Enemy &enemy)
        {
            if (CheckCollisionCircles((Vector2){(float)x, (float)y}, radius, (Vector2){(float)enemy.x, (float)enemy.y}, enemy.radius))
            {
                enemy.health -= 10;
            }
        }
};

void DrawHealthValue(int health)
{
    DrawText(TextFormat("Health: %d", health), 10, 10, 20, WHITE);
}

int main()
{
    bool isPaused = false;
    bool gameOver = false;
    float screenWidth = 800;
    float screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);

    Player player(400, 300, 50, RED, 100);
    Enemy enemy(100, 100, 30, BLUE, 50);
    
    double lastDamageTime = 0.0; // Fixed: Use double for Raylib's GetTime()

    while (!WindowShouldClose())
    {
        // --- 1. INPUT & TOGGLES (Always check) ---
        if (IsKeyPressed(KEY_F)) ToggleFullscreen();
        if (IsKeyPressed(KEY_P) && !gameOver) isPaused = !isPaused;
        
        // If game is over, press R to restart
        if (gameOver && IsKeyPressed(KEY_R)) {
            player.x = 400;
            player.y = 300;
            player.health = 100;
            enemy.x = 100;
            enemy.y = 100;
            enemy.health = 50;
            gameOver = false;
        }

        // --- 2. GAME LOGIC (Only update if running) ---
        if (!isPaused && !gameOver)
        {
            player.Move();
            enemy.MoveTowardsPlayer(player.x, player.y);

            // Player attacking enemy (Trigger punch with SPACE key)
            if (IsKeyPressed(KEY_SPACE)) {
                player.Punch(enemy);
            }

            // Enemy damaging player collision
            if (enemy.health > 0 && CheckCollisionCircles((Vector2){(float)player.x, (float)player.y}, player.radius, (Vector2){(float)enemy.x, (float)enemy.y}, enemy.radius))
            {
                double currentTime = GetTime(); 
                if (currentTime - lastDamageTime > 1.0) // 1 second cooldown
                {
                    player.health -= 20; // Noticeable health drop
                    lastDamageTime = currentTime;
                }
            }

            // Check Win/Loss conditions
            if (player.health <= 0) gameOver = true;
        }

        // --- 3. DRAWING ---
        BeginDrawing();
        ClearBackground(BLACK);

        player.Draw();
        enemy.Draw();
        
        DrawHealthValue(player.health);
        if (enemy.health > 0) {
            DrawText(TextFormat("Enemy Health: %d", enemy.health), 10, 40, 20, WHITE);
        } else {
            DrawText("Enemy Defeated!", 10, 40, 20, GREEN);
        }

        // Overlays
        if (isPaused) {
            DrawText("Game Paused", 320, 280, 40, YELLOW);
        }
        
        if (gameOver) {
            DrawText("Game Over!", 320, 250, 40, RED);
            DrawText("Press 'R' to Restart", 290, 310, 20, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}