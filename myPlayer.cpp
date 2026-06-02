#include <iostream>
#include <string>
#include <vector>

class Player {

public:

    std::string name;

    int health;
    int strength;
    int speed;
    int stamina;

    std::string status;

    std::vector<std::string> inventory;

    void showStats() {

        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Stamina: " << stamina << std::endl;
        std::cout << "Status: " << status << std::endl;
    }

    void showInventory() {

        std::cout << "Inventory:" << std::endl;

        for (std::string item : inventory) {
            std::cout << "- " << item << std::endl;
        }
    }
};

int main() {

    Player leonardo;

    leonardo.name = "Leonardo";
    // Set properties
    leonardo.health = 100;
    leonardo.strength = 15;
    leonardo.speed = 12;
    leonardo.stamina = 20;

    leonardo.status = "Alive";

    leonardo.inventory.push_back("Sword");
    leonardo.inventory.push_back("Potion");
    leonardo.inventory.push_back("Shield");

    leonardo.showStats();

    std::cout << std::endl;

    leonardo.showInventory();

    return 0;
}