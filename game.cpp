#include "raylib.h"

// Helper macro to calculate the scaling aspect ratio dynamically
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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
            if (health <= 0) return; 
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

        void Move() 
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
    
    // 1. FIXED LOGICAL RESOLUTION: The gameplay field is always calculated at 1080p
    const int virtualWidth = 1920;
    const int virtualHeight = 1080;
    
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    
    // 2. WINDOW INITIALIZATION: Starts up in a compact 800x600 desktop window frame
    InitWindow(800, 600, "Game - Adaptive Display");
    
    InitAudioDevice();
    SetTargetFPS(60);

    // Initialize the virtual render canvas texture mapping
    RenderTexture2D targetCanvas = LoadRenderTexture(virtualWidth, virtualHeight);
    SetTextureFilter(targetCanvas.texture, TEXTURE_FILTER_BILINEAR); // Keeps scaling crisp

    // Load sound
    Music music = LoadMusicStream("Assets/GHZ.mp3");
    PlayMusicStream(music);

    Player player(960, 540, 50, RED, 100); // Centered coordinates updated for 1080p space
    Enemy enemy(200, 200, 30, BLUE, 50);
    double lastDamageTime = 0.0; 

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        // Calculate how much to scale the canvas based on the actual desktop window dimensions
        float scale = MIN((float)GetScreenWidth() / virtualWidth, (float)GetScreenHeight() / virtualHeight);

        // --- 1. INPUT & TOGGLES ---
        if (IsKeyPressed(KEY_F)) 
        {
            ToggleFullscreen();
            
            // Explicit sizing check depending on the current monitor display mode
            if (IsWindowFullscreen()) 
            {
                SetWindowSize(1920, 1080); // Snap display context to 1080p standard
            } 
            else 
            {
                SetWindowSize(800, 600);   // Snap desktop frame smoothly back to 800x600
            }
        }
        
        if (IsKeyPressed(KEY_P) && !gameOver) isPaused = !isPaused;
        
        if (gameOver && IsKeyPressed(KEY_R)) {
            player.x = 960;
            player.y = 540;
            player.health = 100;
            enemy.x = 200;
            enemy.y = 200;
            enemy.health = 50;
            gameOver = false;
        }

        // --- 2. GAME LOGIC ---
        if (!isPaused && !gameOver)
        {
            player.Move();
            enemy.MoveTowardsPlayer(player.x, player.y);

            if (IsKeyPressed(KEY_SPACE)) {
                player.Punch(enemy);
            }

            if (enemy.health > 0 && CheckCollisionCircles((Vector2){(float)player.x, (float)player.y}, player.radius, (Vector2){(float)enemy.x, (float)enemy.y}, enemy.radius))
            {
                double currentTime = GetTime(); 
                if (currentTime - lastDamageTime > 1.0) 
                {
                    player.health -= 20; 
                    lastDamageTime = currentTime;
                }
            }

            if (player.health <= 0) gameOver = true;
        }

        // --- 3. RENDERING TO THE VIRTUAL CANVAS (1920x1080 coordinates) ---
        BeginTextureMode(targetCanvas);
            ClearBackground(BLACK);

            player.Draw();
            enemy.Draw();
            
            DrawHealthValue(player.health);
            if (enemy.health > 0) {
                DrawText(TextFormat("Enemy Health: %d", enemy.health), 10, 40, 20, WHITE);
            } else {
                DrawText("Enemy Defeated!", 10, 40, 20, GREEN);
            }

            if (isPaused) {
                DrawText("Game Paused", 860, 500, 40, YELLOW);
            }
            
            if (gameOver) {
                DrawText("Game Over!", 860, 470, 40, RED);
                DrawText("Press 'R' to Restart", 830, 530, 20, WHITE);
            }

            if (music.ctxData == nullptr) {
                DrawText("FILE ERROR: 'Assets/GHZ.mp3' not found!", 10, 70, 20, RED);
            }
        EndTextureMode();

        // --- 4. DISPLAYING SCALED TEXTURE ON PHYSICAL MONITOR ---
        BeginDrawing();
            ClearBackground(DARKGRAY); // Background framing color outside the game texture canvas

            // Render scaled layout into the center of whatever window container exists
            DrawTexturePro(
                targetCanvas.texture,
                (Rectangle){ 0.0f, 0.0f, (float)targetCanvas.texture.width, (float)-targetCanvas.texture.height },
                (Rectangle){ 
                    ((float)GetScreenWidth() - ((float)virtualWidth * scale)) * 0.5f,
                    ((float)GetScreenHeight() - ((float)virtualHeight * scale)) * 0.5f,
                    (float)virtualWidth * scale,
                    (float)virtualHeight * scale 
                },
                (Vector2){ 0, 0 },
                0.0f,
                WHITE
            );
        EndDrawing();
    }
    
    UnloadRenderTexture(targetCanvas); 
    UnloadMusicStream(music); 
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
