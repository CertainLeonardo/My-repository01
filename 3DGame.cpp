#include <raylib.h>
#include <iostream>

class Player
{
public:
    int health;
    float x;
    float y;
    float z;

    void PlayerPos(int posX, int posY, int posZ)
    {
        x = posX;
        y = posY;
        z = posZ;

        std::cout << "Position on the X axis is: " <<  x << std::endl;
        std::cout << "Position on the Y axis is: " << y << std::endl;
        std::cout << "Position on the Z axis is: " << z << std::endl;
    }

};

void PlayerStart()
{
    Player player1;

    player1.health = 100;
    player1.x = 50;
    player1.y = 50;
    player1.z = 25;

    player1.PlayerPos(player1.x, player1.y, player1.z);
}

int main(){

    float ScreenWidth = 1200;
    float ScreenHeight = 700;

    Camera3D camera = { 0 };
    camera.position = { 8.0f, 8.0f, 8.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;\

    PlayerStart();

    InitWindow(ScreenWidth, ScreenHeight, "My 3D Game!");
    SetTargetFPS(60);
    Model sword = LoadModel("Assets/Sword.glb");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(GRAY);

        BeginMode3D(camera);

        DrawModel(sword, {0.0f, 0.0f, 0.0f}, 0.7f, WHITE);
        
        //DrawCube({0, 0, 0}, 2, 2, 2, RED);
        DrawGrid(20, 1.0f);

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}