#include "weather.hpp"
#include <iostream>

void badminton (std::string day, std::string temp, std::string precipitation, std::string breeze, std::string humidity) {
    if (day == "воскресенье" || day == "Воскресенье" || day == "Воскресение" || day == "воскресение" || day == "Воскр" || day == "воскр"){
        if (temp == "жаркая" || temp == "Жаркая" || temp == "теплая" || temp == "Теплая" || temp == "Тепло" || temp == "тепло" || temp == "жарко" || temp == "Жарко"){
            if (precipitation == "ясно" || precipitation == "Ясно" || precipitation == "Ясная" || precipitation == "ясная"){
                if (breeze == "нет" || breeze == "Нет" || breeze == "Нету" || breeze == "нету" || breeze == "Не" || breeze == "не"){
                    if (humidity == "низкая" || humidity == "Низкая" || humidity == "Низко" || humidity ==  "низко"){
                        std::cout << "Да, сегодня играем в бадминтон" << std::endl;
                    }
                }
            }
        }
    }
    else {
        std::cout << "НЕТ БАДМИНТОНА СЕГОДНЯ" << std::endl;
    }
}
