#include <iostream>
#include "BankAccount.hpp"

int main() {
    BankAccount счет("123456789");
    int выбор;

    do {
        std::cout << "\n---------- Меню ----------" << std::endl;
        std::cout << "1. Положить деньги" << std::endl;
        std::cout << "2. Снять деньги" << std::endl;
        std::cout << "3. Посмотреть баланс" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> выбор;

        switch (выбор) {
            case 1: {
                double сумма;
                std::cout << "Введите сумму для пополнения: ";
                std::cin >> сумма;
                счет.положить(сумма);
                std::cout << "На счет добавлено: " << сумма << " руб." << std::endl;
                break;
            }
            case 2: {
                double сумма;
                std::cout << "Введите сумму для снятия: ";
                std::cin >> сумма;
                счет.снять(сумма);
                break;
            }
            case 3: {
                std::cout << "Текущий баланс: " << счет.получитьБаланс() << " руб." << std::endl;
                break;
            }
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор. Пожалуйста, попробуйте еще раз." << std::endl;
        }
    } while (выбор != 0);

    return 0;
}
