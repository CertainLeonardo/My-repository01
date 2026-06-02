#include <raylib.h>
#include <iostream>

int newFunction() {
    std::cout << "This is a new function!" << std::endl;
    return 0;
}

int main() {
    // Initialize the window
    InitWindow(1289, 720, "My Game");
    newFunction(); // Call the new function to demonstrate its usage
    int userInput;
    std::cin >> userInput; // Wait for user input before starting the game loop

    // Main game loop
    while (!WindowShouldClose()) {
        // Update game logic here

        // Draw everything
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib, My name is Leonardo!", 190, 200, 20, RED);
        // add a statement to full screen    
        if (IsKeyPressed(KEY_F)) {
            ToggleFullscreen();
        }
        EndDrawing();
    }

    // Close the window and clean up resources
    CloseWindow();
    return 0;
}

//command to compile: g++ game.cpp -o game -lraylib -lopengl32 -lgdi32 -lwinmm
// Note: Make sure to have the Raylib library installed and properly linked when comppiling the code.
// Make sure to have the correct headers in your project, and use the correct flags for linking the Raylib Library.
// Raylib uses the OpenGL Library API to render graphics, so you need to link against the OpenGL library as well.
// And remember the most important thing is to have fun while coding your game!