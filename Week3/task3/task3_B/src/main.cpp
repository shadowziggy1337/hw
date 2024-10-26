#include <iostream>
#include "merge_sort.hpp"

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    double* arr = new double[size];

    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
