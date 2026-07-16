#include <iostream>
using namespace std;

int main() {
    int table[5];
    table[0] = 1;
    table[1] = 2;
    table[2] = 3;
    table[3] = 4;
    table[4] = 5;

    for (int i = 0; i < 5; i++) {
        std::cout << table[i] << " ";
    }

    cout << "Hello, world!" << endl;
    return 0;
}