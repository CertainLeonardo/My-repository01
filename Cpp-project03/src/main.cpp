#include <iostream>
using namespace std;

struct Point {
    float x;
    float y;

    void print() {
        cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
    }
};

class User {
public:
    // Variables (Attributes / Data stored in the object)
    string name;
    int age;
    float health = 100.0f;

    void takeInput() {
        cout << "Enter your name: ";
        cin >> name;

        if (name == name) {
            cout << "Do you want to change your name? (y/n)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y') {
                cout << "Enter your new name: ";
                cin >> name;
                cout << "Your name has been changed to: " << name << endl;
            }
            else {
                cout << "Your name remains: " << name << endl;
            }
        }

        cout << "Enter your age: ";
        cin >> age;

        if (age < 0) {
            cout << "Age cannot be negative. Setting age to 0." << endl;
            age = 0;
        }
        else if (age > 120) {
            cout << "Age cannot be greater than 120. Setting age to 120." << endl;
            age = 120;
        }
        else if (age == age) {
            cout << "Do you want to change your age? (y/n)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y') {
                cout << "Enter your new age: ";
                cin >> age;
                cout << "Your age has been changed to: " << age << endl;
            }
            else {
                cout << "Your age remains: " << age << endl;
            }
        }

        cout << "Hello " << name << ", you are " << age << " years old." << endl;
    }

    void takeDamage(float damage) {
        health -= damage;

        if (health > 0) {
            cout << "You have " << health << " health left." << endl;
        } else {
            cout << "You are dead." << endl;
        }
    }
};

float math(float a, float b) {
    return a + b;
}

int main() {
    // Create a User object
    User player1;
    player1.takeInput();
    player1.takeDamage(20.0f);

    // Create a Point data type
    Point mypoint = { 0.0f, 0.0f };
    cout << "Enter point coordinates (x, y): " << endl;
    cin >> mypoint.x >> mypoint.y;
    mypoint.print();
    
    // math function
    cout << "Enter two numbers: ";
    float a;
    float b;    
    cin >> a >> b;
    float sum = math(a, b);
    cout << "The sum is: " << sum << endl;

    return 0;
}