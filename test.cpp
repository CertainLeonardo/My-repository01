#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    bool running = true;

    while (running) {
        int secret = rand() % 10 + 1;
        int guess = 0;
        int attempts = 0;

        cout << "Guess the number between 1 and 10\n";

        while (guess != secret) {
            cout << "Enter guess: ";
            cin >> guess;
            attempts++;

            if (guess > secret) {
                cout << "Too high\n";
            } else if (guess < secret) {
                cout << "Too low\n";
            } else {
                cout << "Correct\n";
                cout << "Attempts: " << attempts << "\n";
            }
        }

        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;

        if (choice != 'y') {
            running = false;
        }
    }

    cout << "Game over\n";
    return 0;
}