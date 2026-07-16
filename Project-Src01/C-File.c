#include <stdio.h>  // Includes standard input/output library - needed to use printf()
#include <Windows.h>

void printMessage() {
    // Function to print a message to the console - demonstrates function definition and usage
    
    printf("Hello, World!\n");  // Prints "Hello, World!" followed by a newline
}

void printSum(int a, int b) {
    // Function to calculate and print the sum of two integers - demonstrates parameter passing
    
    int sum = a + b;  // Calculates sum of a and b
    printf("Sum: %d\n", sum);  // Prints the result to console
}

void printProduct(float x, float y) {
    // Function to calculate and print the product of two floats - demonstrates parameter passing
    
    float product = x * y;  // Calculates product of x and y
    printf("Product: %.2f\n", product);  // Prints the result to console with 2 decimal places
}

void printGreeting(const char* name) {
    // Function to print a personalized greeting - demonstrates string handling
    
    printf("Hello, %s!\n", name);  // Prints greeting with the provided name
}

int whileLoop() {
    // Demonstrating a while loop - iterates until a condition is false
    int count = 1;  // Initializes counter variable
    while (count <= 5) {  // Loop continues as long as count is less than or equal to 5
        printf("Count: %d\n", count);  // Prints current count value
        count++;  // Increments count by 1
    }

    return 0;  // Returns 0 to indicate successful completion of the function
}

int Forloop() {
    // now demonstrating a loop - iterates 5 times and prints the iteration number
    for (int i = 1; i <= 5; i++) {
        printf("Iteration: %d\n", i);  // Prints current iteration number
    }

    return 0;  // Returns 0 to indicate successful completion of the function
}

void conditionalStatements(int number) {
    // Demonstrating conditional statements - checks if number is positive, negative, or zero
    if (number > 0) {  // Checks if number is greater than 0
        printf("The number %d is positive.\n", number);  // Prints message for positive number
    } else if (number < 0) {  // Checks if number is less than 0
        printf("The number %d is negative.\n", number);  // Prints message for negative number
    } else {  // If neither condition is true, number must be zero
        printf("The number is zero.\n");  // Prints message for zero
    }
}

void switchCaseExample(int day) {
    // Demonstrating switch-case statement - prints the name of the day based on the number provided
    switch (day) {  // Evaluates the value of day
        case 1:  // If day is 1
            printf("Monday\n");  // Prints Monday
            break;  // Exits the switch statement
        case 2:  // If day is 2
            printf("Tuesday\n");  // Prints Tuesday
            break;  // Exits the switch statement
        case 3:  // If day is 3
            printf("Wednesday\n");  // Prints Wednesday
            break;  // Exits the switch statement
        case 4:  // If day is 4
            printf("Thursday\n");  // Prints Thursday
            break;  // Exits the switch statement
        case 5:  // If day is 5
            printf("Friday\n");  // Prints Friday
            break;  // Exits the switch statement
        case 6:  // If day is 6
            printf("Saturday\n");  // Prints Saturday
            break;  // Exits the switch statement
        case 7:  // If day is 7
            printf("Sunday\n");  // Prints Sunday
            break;  // Exits the switch statement
        default:  // If none of the above cases match
            printf("Invalid day number.\n");  // Prints error message for invalid input
    }
}

int arrayExample() {
    // Demonstrating array usage - stores multiple values of the same type
    int numbers[5] = {10, 20, 30, 40, 50};  // Declares an array of integers with 5 elements

    for (int i = 0; i < 5; i++) {  // Loops through each element of the array
        printf("Element %d: %d\n", i, numbers[i]);  // Prints index and value of each element
    }

    return 0;  // Returns 0 to indicate successful completion of the function
}

int main() {
    // main() is the entry point where program execution starts - required in every C program
    
    int age = 25;  // Declares integer variable and assigns value - stores whole numbers in memory
    double height = 5.9;  // Declares double variable and assigns value - stores decimal numbers in memory
    float weight = 70.5f;  // Declares float variable and assigns value - stores decimal numbers with less precision than double
    
    printf("Age: %d\n", age);  // Prints text and variable value to console - %d is placeholder for integer
    printf("Height: %lf\n", height);  // Prints text and variable value to console - %lf is placeholder for double
    printf("Weight: %f\n", weight);  // Prints text and variable value to console - %f is placeholder for float

    printMessage();  // Calls function to print a message - demonstrates function invocation
    printSum(10, 20);  // Calls function to print sum of two integers
    printProduct(3.5f, 2.0f);  // Calls function to print product of two floats
    printGreeting("Alice");  // Calls function to print personalized greeting

    whileLoop();  // Calls function to demonstrate while loop
    conditionalStatements(-5);  // Calls function to demonstrate conditional statements
    switchCaseExample(3);  // Calls function to demonstrate switch-case statement
    arrayExample();  // Calls function to demonstrate array usage

    // "\n" creates a newline - improves readability of output

    // lets create a Microsoft window that displays a message box with a greeting
    // let's make the window 100 pixels wide and 100 pixels tall, and display the message "Hello, World!" in it
    // to do this, we will use the MessageBox function from the Windows API
    // example: MessageBox(NULL, "Hello, World!", "My Application", MB_OK);
    // Note: This part requires Windows.h and is platform-specific
    MessageBox(NULL, "Hello, World!", "My Application", MB_OK);
    


    // now to make the program more interactive, we can add user input functionality
    int userAge;
    printf("Enter your age: ");  // Prompts user for input
    scanf("%d", &userAge);  // Reads integer input from user and stores it
    printf("Your age is: %d\n", userAge);  // Prints the entered age

    return 0;  // Returns 0 to operating system - signals program ended successfully
}