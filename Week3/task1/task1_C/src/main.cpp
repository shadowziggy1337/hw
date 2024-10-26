#include "weather.hpp"
#include <iostream>

int main() {
    std::string day, temp, precipitation, breeze, humidity;
    std::cout << "Узнаем, хотим ли мы сегодня поиграть в бадминтон" << std::endl;
    std::cout << "Введите день недели: " << std::endl;
    std::cin >> day;
    std::cout << "Введите темературу из списка: жаркая, теплая, холодная: " << std::endl;
    std::cin >>temp;
    std::cout << "Есть ли осадки, выберите из списка: ясно, облачно, дождь, снег, град: " << std::endl;
    std::cin >>precipitation;
    std::cout << "На улице есть ветер?: " << std::endl;
    std::cin >>breeze;
    std::cout << "Какая на улице влажность?: " << std::endl;
    std::cin >>humidity;
    
    badminton(day, temp, precipitation, breeze, humidity);

    return 0;
}