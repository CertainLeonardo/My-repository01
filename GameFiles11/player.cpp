#include "player.hpp"

void MovePlayer(Player &player) {
    if (IsKeyDown(KEY_W)) player.position.z -= player.speed;
    if (IsKeyDown(KEY_S)) player.position.z += player.speed;
    if (IsKeyDown(KEY_A)) player.position.x -= player.speed;
    if (IsKeyDown(KEY_D)) player.position.x += player.speed;
}
