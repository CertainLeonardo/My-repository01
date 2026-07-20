#include "player.hpp"
#include <raymath.h> // Required for Vector3 math functions

void MovePlayer(Player &player, const Camera3D &camera) {
    // 1. Calculate the raw camera forward vector (Target minus Position)
    Vector3 forward = Vector3Subtract(camera.target, camera.position);
    
    // Flatten it so moving "forward" doesn't make the player fly up or dig down
    forward.y = 0.0f; 
    forward = Vector3Normalize(forward);

    // 2. Calculate the camera right vector using the world up axis
    Vector3 right = Vector3CrossProduct(forward, camera.up);
    right = Vector3Normalize(right);

    // 3. Apply movement based on keys pressed
    Vector3 moveDirection = { 0.0f, 0.0f, 0.0f };

    if (IsKeyDown(KEY_W)) moveDirection = Vector3Add(moveDirection, forward);
    if (IsKeyDown(KEY_S)) moveDirection = Vector3Subtract(moveDirection, forward);
    if (IsKeyDown(KEY_A)) moveDirection = Vector3Subtract(moveDirection, right);
    if (IsKeyDown(KEY_D)) moveDirection = Vector3Add(moveDirection, right);

    // Normalize total movement so diagonal walking isn't accidentally faster
    if (Vector3Length(moveDirection) > 0.0f) {
        moveDirection = Vector3Normalize(moveDirection);
        // Scale by player speed
        moveDirection = Vector3Scale(moveDirection, player.speed);
        // Add to player position
        player.position = Vector3Add(player.position, moveDirection);
    }
}
