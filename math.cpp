#include <iostream>
#include <string>

int myFunction(int num1, int num2) {
    int a = num1;
    int b = num2;
    int sum = a + b;
    return sum;
}

// Function definition
int addNumbers(int num1, int num2) {
    int sum = num1 + num2;
    return sum; // Sends the integer result back
}

int numAge(int age) {
    // This if statement determines the age of the user 
    //and prints out a message accordingly in the terminal console.

    if (age <= 18){
        std::cout << "You are an adolescent." << std::endl;
    }
    else if (age > 18 && age <= 65) {
        std::cout << "You are an adult." << std::endl;
    }
    else {
        std::cout << "You are a senior." << std::endl;
    }
    // The function returns the age back to the main function
    return age;
}

int main() {
    // Calling the function and storing its output
    int result = addNumbers(5, 10); 
    int myResult = myFunction(5, 25);
    std::cout << "My result is: " << myResult << std::endl;

    int givenAge;
    std::cin >> givenAge;
    int age = numAge(givenAge);

    if (myResult == 30) {
        std::cout << "The result is exactly 30." << std::endl;

    } 
    else if (myResult >= 25) {
        std::cout << "The result is greater than 25." << std::endl;
    }
    else {
        std::cout << "The result is 20 or less." << std::endl;
    }

    //std::cout << "The sum is: " << result; 
    //Close the Program
    return 0;
}