#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

struct Player {
    Vector3 position;
    float speed;
};

// Updated: Now accepts a reference to the Camera3D
void MovePlayer(Player &player, const Camera3D &camera);

#endif
