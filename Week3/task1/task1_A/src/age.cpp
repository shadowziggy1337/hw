#include "age.hpp"
#include <iostream>

void printAge(int age) {
    if (age <= 0) {
        std::cout << "К сожалению, вы ввели возраст эмбриона";
    } else if (age % 100 >= 11 && age % 100 <= 14) {
        std::cout << "Вам " << age << " лет";
    } else {
        switch (age % 10) {
            case 1:
                std::cout << "Вам " << age << " год";
                break;
            case 2:
            case 3:
            case 4:
                std::cout << "Вам " << age << " года";
                break;
            default:
                std::cout << "Вам " << age << " лет";
                break;
        }
    }
}