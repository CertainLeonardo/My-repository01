#include <iostream>
#include <string>

// I like to write C++ programs

namespace MyProgram {
    void run() {
        std::cout << "Running My Program Successfully!.." << std::endl;
    }
}

namespace secondFunction {
    void run() {
        std::cout << "Running the second function successfully!.." << std::endl;
        std::cout << "This is the end of the second function." << std::endl;
        int a = 10;
        int b = 20;
    }
}

int main() {
    MyProgram::run();
    secondFunction::run();
    std::string name = "Leonardo";

    using namespace MyProgram;
    using namespace secondFunction;

    const double PI = 3.14159;
    //PI = 3.14159; // This will cause a compilation error because PI is declared as const
    double radius = 10.0;
    double diameter = 2 * radius;
    double circumference = 2 * PI * radius;

    std::cout << circumference << "cm" << std::endl;

    const int SPEED_OF_LIGHT = 299792458; // in meters per second
    std::cout << "The speed of light is " << SPEED_OF_LIGHT << " m/s." << std::endl;
    std::cout << "This is the end of the program." << std::endl;

    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    std::cout << "The screen resolution is " << WIDTH << "x" << HEIGHT << "." << std::endl;

    return 0;
}