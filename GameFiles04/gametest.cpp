#include <raylib.h>
#include <iostream>

class Enemy
{
public:
    std::string name;
    float health;
    float speed;
    int positionX;
    int positionY;
    Enemy(std::string enemyName, float enemyHealth, float enemySpeed, int posX, int posY)
    {
        name = enemyName;
        health = enemyHealth;
        speed = enemySpeed;
        positionX = posX;
        positionY = posY;
    }
};

void PrintEnemyInfo(const Enemy& enemy)
{
    std::cout << "Enemy Name: " << enemy.name << std::endl;
    std::cout << "Enemy Health: " << enemy.health << std::endl;
    std::cout << "Enemy Speed: " << enemy.speed << std::endl;
    std::cout << "Enemy Position: (" << enemy.positionX << ", " << enemy.positionY << ")" << std::endl;
}

class Player
{
public:
    std::string name;
    int health;
    float speed;
    float positionX;
    float positionY;

    Player(std::string playerName, int playerHealth, float playerSpeed, float posX, float posY)
    {
        name = playerName;
        health = playerHealth;
        speed = playerSpeed;
        positionX = posX;
        positionY = posY;
    }
};

int main()
{
    // Window setup
    const int screenWidth = 1280;
    const int screenHeight = 720;
    // Create a table of all the controls to move the rectangle

    std::string controls = "Controls:\n"
                       "WASD or Arrow Keys: Move Rectangle\n"
                       "SPACE or F: Play Sound\n"
                       "F11: Toggle Fullscreen\n"
                       "Left Click: Print Mouse Position";
    std::cout << controls << std::endl;

    int arrayControls[5] = {KEY_W, KEY_A, KEY_S, KEY_D, KEY_SPACE};
    
    // Set Vsynce to avoid screen tearing
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "My First Raylib Game!");

    // Audio setup
    InitAudioDevice();
    // creat a enemy instance
    Enemy enemy("Robot", 50, 2.5f, 200, 200);
    // Create a player instance
    Player player("Megaman", 100, 5, 50, 50);

    // Set player properties and information
    player.name = "Megaman";
    player.health = 100;
    player.speed = 225;
    player.positionX = 50;
    player.positionY = 50;
    // Print player information to the console
    std::cout << "Player Name: " << player.name << std::endl;
    std::cout << "Player Health: " << player.health << std::endl;
    std::cout << "Player Speed: " << player.speed << std::endl;
    std::cout << "Player Position: (" << player.positionX << ", " << player.positionY << ")" << std::endl;

    // Load assets ONCE
    Texture2D megaman = LoadTexture("Assets/Megaman.png");
    Sound soundEffect = LoadSound("Assets/Sound02.mp3");

    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose())
    {
        // --------------------
        // Update
        // --------------------

        Vector2 mousePosition = GetMousePosition();

        // Play sound when SPACE is pressed
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_F)) // Play sound when SPACE or F is pressed
        {
            PlaySound(soundEffect);
            std::cout << "Played sound effect!\n";
        }

        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();

            SetTargetFPS(60);
        }

        // Print mouse position only when left-clicking
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            std::cout << "Mouse Position: ("
                      << mousePosition.x
                      << ", "
                      << mousePosition.y
                      << ")\n";
        }

        // --------------------
        // Draw
        // --------------------

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Draw Mega Man
        DrawTexture(megaman, player.positionX, player.positionY, WHITE);

        float dt = GetFrameTime();

        if (IsKeyDown(KEY_D)) player.positionX += player.speed * dt;
        if (IsKeyDown(KEY_A)) player.positionX -= player.speed * dt;
        if (IsKeyDown(KEY_W)) player.positionY -= player.speed * dt;
        if (IsKeyDown(KEY_S)) player.positionY += player.speed * dt;

        // Draw text takes a string, position, font size, and color
        DrawText(
            "Congrats! You created your first window!",
            10,
            25,
            20,
            DARKGRAY);

        std::string healthText = "Health: " + std::to_string(player.health);

        DrawText(
            healthText.c_str(),
            1000,
            50,
            20,
            GREEN
        );

        // Draw mouse coordinates
        DrawText(
            TextFormat("Mouse: %.0f, %.0f",
            mousePosition.x,
            mousePosition.y),
            10,
            10,
            20,
            BLACK);

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(megaman);
    UnloadSound(soundEffect);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}