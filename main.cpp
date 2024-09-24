#include <iostream>
#define CONSTANT 10
int add(int a, int b);
int main() {
    std::cout << "Hello World"<< std::endl;
    int speed = 0;
    std::cout << "Enter Number" << std::endl;
    std::cin  >> speed;
    std::cout << "speed: "<< speed << add(speed, CONSTANT) << std::endl;
    return 0;
}
int add(int a, int b) {
    return a + b;
}