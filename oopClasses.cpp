#include <iostream>
#include <string>

class Player {
    public:
        std::string name;
        int health;
        int xp;

        void talk(std::string text_to_say) {
            std::cout << name << " says: " << text_to_say << std::endl;
        }
};

int main() {
    // Select your player and create an object of the Player class
    // using switches!

    int player_selection;
    std::cout << "Select your Player! : ";
    std::cin >> player_selection;

    while (player_selection < 1 || player_selection > 4) {
        std::cout << "Invalid selection! Please select a player between 1 and 4: ";
        std::cin >> player_selection;
    }
    switch(player_selection) {
        case 1: {
            Player player1;
            player1.name = "Leonardo";
            std::cout << "Player 1 selected! " << player1.name << std::endl;
            player1.health = 100;
            player1.xp = 12;
            player1.talk("I am the leader!");
            break;
        }
        case 2: {
            Player player2;
            player2.name = "Donatello";
            std::cout << "Player 2 selected! " << player2.name << std::endl;
            player2.health = 100;
            player2.xp = 12;
            player2.talk("I am the tech guy!");
            break;
        }
        case 3: {
            Player player3;
            player3.name = "Raphael";
            std::cout << "Player 3 selected! " << player3.name << std::endl;
            player3.health = 100;
            player3.xp = 12;
            player3.talk("I am the muscle!");
            break;
        }
        case 4: {
            Player player4;
            player4.name = "Michelangelo";
            std::cout << "Player 4 selected! " << player4.name << std::endl;
            player4.health = 100;
            player4.xp = 12;
            player4.talk("I am the party dude!");
            break;
        }
        default: 
            std::cout << "Invalid selection!" << std::endl;
            break;
    }

    return 0;
}