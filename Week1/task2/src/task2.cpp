#include <iostream>
#include <limits> // Для получения границ типов данных

int main() {
    std::cout << "Выберите, какую информацию о максимальных и минимальных значениях типов данных вы хотите увидеть:" << std::endl;
    std::cout << "1. int\n";
    std::cout << "2. float\n";
    std::cout << "3. double\n";

    int choice;
    std::cout << "Введите номер типа данных (1-3): ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "int:\n";
            std::cout << "Минимальное значение: " << std::numeric_limits<int>::min() << std::endl;
            std::cout << "Максимальное значение: " << std::numeric_limits<int>::max() << std::endl;
            break;
        }
        case 2: {
            std::cout << "float:\n";
            std::cout << "Минимальное значение: " << std::numeric_limits<float>::min() << std::endl;
            std::cout << "Максимальное значение: " << std::numeric_limits<float>::max() << std::endl;
            break;
        }
        case 3: {
            std::cout << "double:\n";
            std::cout << "Минимальное значение: " << std::numeric_limits<double>::min() << std::endl;
            std::cout << "Максимальное значение: " << std::numeric_limits<double>::max() << std::endl;
            break;
        }
        default:
            std::cout << "Неверный ввод. Пожалуйста, выберите правильный номер типа данных (1-3).";
    }

    return 0;
}

