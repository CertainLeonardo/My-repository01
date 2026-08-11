#include <iostream>
#include <vector>

// typedefs for commonly used data types to give them more meaninful names and to make the code more readable
typedef std::string String;
// typedef for a vector of integers to make it easier to declare and use vectors of integers
typedef std::vector<int> IntVector;

// Global variable declaration
int globalVar = 0;

// Function to demonstrate the use of namespaces and global variables
namespace first 
{
    // Declare two integer variables x and y, and a string variable text within the first namespace
    int x = 42;
    int y = 100;

    String text = "Hello, from first namespace!";
    
    // Function to print the text variable from the first namespace
    void printText()
    {
        std::cout << text << std::endl;
    }
}

// Another namespace to demonstrate the use of multiple namespaces
namespace second
{
    // Declare two integer variables x and y, and a string variable text within the second namespace
    int x = 10;
    int y = 20;
    String text = "Hello from second namespace!";
    
    // Function to print the text variable from the second namespace
    void printText()
    {
        std::cout << text << std::endl;
    }
}

void table()
{
    // This array has a fixed size of 5 and is initialized with values from 1 to 5
    int array[5] = {1, 2, 3, 4, 5};

    // Loop through the array and print each element to the console by incrementing the index variable i from 0 to 4
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << " " << std::endl;
    }
}


int math(int x, int y) // set up parameters for the math function.
{
    // we will use the comparison greater than or equal to operator ">=" to produce a bool value 
    if (x >= y)
    {
        std::cout << "x is greater than or equal to y" << std::endl;
        return x; // return the value of x if the condition is true
    }
    return y; // return the value of y if the condition is false
}

int main()
{
    // Call the table function to demonstrate the use of arrays and loops in C++
    table();

    std::cout << "\n";

    // Im gonna use the global variable globarVar and increment it by 1 using the assigment operator +=
    globalVar += 1;
    std::cout << globalVar << std::endl;
    // or 
    globalVar++; // you can also use the arithmetic operator ++ to increment the value of globar Var by 1
    std::cout << globalVar << std::endl;

    // Print a newline, that's it
    std::cout << "\n";

    // Call the printText function from both namespaces to demonstrate how to access functions from different namespaces
    // namspaces use the resolution scope operator :: to access the function and variables defined within them
    first::printText();
    second::printText();

    std::cout << "\n";

    // i will declare two variables here
    int choice1;
    int choice2;
    
    // then use the standard input
    std::cout << "Pick your first number: " << std::endl;
    std::cin >> choice1;
    std::cout << "Pick your second number: " << std::endl;
    std::cin >> choice2;
    math(choice1, choice2);

    return 0;
}