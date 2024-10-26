#include "age.hpp"
#include <iostream>

int main() {
    int age;
    std::cout << "Введите свой возраст: ";
    std::cin >> age;
    
    printAge(age);

    return 0;
}