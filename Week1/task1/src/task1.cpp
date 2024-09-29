#include <iostream>
#include <string>

int main() {
    std::string userName;
    
    std::cout << "Введите ваше имя: ";
    std::cin >> userName;

    // Формирование приветственной строки
    std::string greeting = "Привет, " + userName + "!";
    
    // Вывод приветственной строки
    std::cout << greeting << std::endl;

    return 0;
}
