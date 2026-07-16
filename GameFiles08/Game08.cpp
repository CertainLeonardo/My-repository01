#include <iostream>

void myFuntion(){
    std::cout << "This is my function!" << "\n";

}

int Math(){
    int a = 5;
    int b = 10;
    int sum = a + b;
    std::cout << sum << std::endl;
    return sum;
}

int loop(){
    for (int i = 0; i < 50; i++){
        std::cout << i << std::endl;
    }
    return 0;
}

int whileLoop(){
    int i = 150;

    while (i > 0){
        std::cout << i << std::endl;
        i++;

        if (i == 500){
            std::cout << "Halfway there!" << std::endl;
            continue;
        }

        if (i > 1000){
            break;
        }
    }
    return 0;
}

int Math2(float a, float b){
    return a / b;
}

int main(){
    std::cout << "Hello, world!" << "\n";
    myFuntion();
    // Math();
    // loop();
    // whileLoop();
    int result = Math2(47, 35);
    std::cout << result << std::endl;
    return 0;
}