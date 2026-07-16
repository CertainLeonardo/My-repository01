#include <iostream>
using namespace std;

int myFunction(float num1, float num2) {
    float sum = num1 + num2;
    cout << "The sum is: " << sum << endl;
    return sum;
    return 0;
}

void math(){
    float num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
}

void ageFunction(){
    double num3, num4;
    cout << "Enter your age: ";
    cin >> num3;

    if (num3 >= 65){
        cout << "You are a senior citizen." << endl;
    }
    else if(num3 >= 18){
        cout << "You are an adult." << endl;
    }
    else{
        cout << "You are a child." << endl;
    }
}

int main() {
    math();
    //
    float num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    myFunction(num1, num2);
    //
    ageFunction();

    return 0;
}