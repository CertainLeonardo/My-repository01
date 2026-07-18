#include <iostream>
#include <raylib.h>

class Player {
public:

    float health = 100.0f;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    Player() {
        std::cout << "Player created!" << std::endl;
    }
};