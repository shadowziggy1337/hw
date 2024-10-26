#include "year.hpp"
#include <iostream>

int main() {
    int month, year;
    std::cout << "Введите месяц: " << std::endl;
    std::cin >> month;
    if (month <=0 || month >=13) {
        std::cout << "К сожалению, вы ввели несуществующий месяц";
        return 0;
    }
    std::cout << "Введите год: " << std::endl;
    std::cin >> year;
    if (year <=0) {
        std::cout << "К сожалению, вы ввели год до рождения Христа";
        return 0;
    }
    
    printyear(month, year);

    return 0;
}