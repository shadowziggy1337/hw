#include <iostream>
#include <string>
#include "regex.hpp"

int main() {
    std::string ipv6;

    std::cout << "Введите адрес IPv6: ";
    std::getline(std::cin, ipv6);

    if (isValidIPv6(ipv6)) {
        std::cout << "Адрес IPv6 '" << ipv6 << "' является валидным." << std::endl;
    } else {
        std::cout << "Адрес IPv6 '" << ipv6 << "' не является валидным." << std::endl;
    }

    return 0;
}
