#include <raylib.h>

class Player 
{
    public:
        int x, y;
        int speed;
        int health;

        Player(int x, int y, int speed, int health) 
        {
            this->x = x;
            this->y = y;
            this->speed = speed;
            this->health = health;
        }
        void Draw()
        {
            DrawCircle(x, y, 20, RED);
        }
};

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "2D Game");

    Player player(screenWidth / 2, screenHeight / 2, 5, 100);

    while (!WindowShouldClose()) 
    {
        if (IsKeyDown(KEY_RIGHT)) player.x += player.speed;
        if (IsKeyDown(KEY_LEFT)) player.x -= player.speed;
        if (IsKeyDown(KEY_UP)) player.y -= player.speed;
        if (IsKeyDown(KEY_DOWN)) player.y += player.speed;

        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}