#include <iostream>
#include <string>
#include "shannon.hpp"

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    double entropy = calculateShannonEntropy(input);  // Вычисление энтропии

    std::cout.precision(2);
    std::cout << "Энтропия: " << std::fixed << entropy << std::endl;

    return 0;
}
