#include <iostream>
#include "arrmax.hpp"

int main() {
    const int maxSize = 100;  // Максимальный размер массива
    double numbers[maxSize];
    int size;

    // Ввод размера массива
    std::cout << "Введите количество элементов массива: ";
    std::cin >> size;

    // Ввод элементов массива
    std::cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }

    int maxCount = findMaxCount(numbers, size);

    // Вывод результата
    std::cout << "Количество чисел, равных максимальному: " << maxCount << std::endl;

    return 0;
}
