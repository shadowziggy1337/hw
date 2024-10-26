#include <iostream>
#include "counter.hpp"

int main() {
    std::string searchSubstring;
    std::cout << "Что ищем: ";
    std::cin >> searchSubstring;

    int n;
    std::cout << "Сколько строк будете вводить: ";
    std::cin >> n;

    std::string inputString;
    int totalOccurences = 0; // Общий счетчик вхождений

    std::cout << "Где ищем:\n";
    // Цикл для ввода строк и подсчета вхождений
    for (int i = 0; i < n; ++i) {
        std::cin >> inputString;
        totalOccurences += countSubstring(inputString, searchSubstring);
    }

    std::cout << "Вывод: " << totalOccurences << std::endl;

    return 0;
}
