#include <iostream>
#include <string>
#include "regex.hpp"

int main() {
    std::string email;

    std::cout << "Введите адрес электронной почты: ";
    std::getline(std::cin, email);

    if (isValidEmail(email)) {
        std::cout << "Адрес электронной почты '" << email << "' является валидным." << std::endl;
    } else {
        std::cout << "Адрес электронной почты '" << email << "' не является валидным." << std::endl;
    }

    return 0;
}

