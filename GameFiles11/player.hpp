#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>

struct Player {
    Vector3 position;
    float speed;
};

void MovePlayer(Player &player);

#endif
