#include "year.hpp"
#include <iostream>

void printyear(int month, int year) {
        switch (month){
            case 1: std::cout << "Январь, в нем 31 день"; break;
            case 2:
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                    std::cout << "Февраль, в нем 29 дней"; break;
                }
                else{
                    std::cout << "Февраль, в нем 28 дней"; break;
                }
            case 3: std::cout << "Март, в нем 31 день"; break;
            case 4: std::cout << "Апрель, в нем 30 дней"; break;
            case 5: std::cout << "Май, в нем 31 день"; break;
            case 6: std::cout << "Июнь, в нем 30 дней"; break;
            case 7: std::cout << "Июль, в нем 31 день"; break;
            case 8: std::cout << "Август, в нем 31 день"; break;
            case 9: std::cout << "Сентябрь, в нем 30 дней"; break;
            case 10: std::cout << "Октябрь, в нем 31 день"; break;
            case 11: std::cout << "Ноябрь, в нем 30 дней"; break;
            case 12: std::cout << "Декабрь, в нем 31 день"; break;
       }
}