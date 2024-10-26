#include <iostream>
#include "array.hpp"

int main() {
    int n;
    std::cout << "Введите верхнюю границу диапазона: ";
    std::cin >> n;

    std::cout << "Простые числа в диапазоне от 2 до " << n << ": ";
    sieveOfEratosthenes(n);

    return 0;
}
