#include <iostream>
#include "median.hpp"

const int MAX_SIZE = 100;

int main() {
    double arr[MAX_SIZE];
    int size;

    std::cout << "Введите количество элементов (не более 100): ";
    std::cin >> size;

    if (size < 1 || size > MAX_SIZE) {
        std::cout << "Ошибка: некорректное количество элементов." << std::endl;
        return 1;
    }

    std::cout << "Введите элементы массива: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    double median;
    findMedian(arr, size, median);
    std::cout << "Медиана: " << median << std::endl;

    return 0;
}
