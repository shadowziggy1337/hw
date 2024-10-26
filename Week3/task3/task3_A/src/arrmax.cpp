#include "arrmax.hpp"

int findMaxCount(double numbers[], int size) {
    double maxValue = numbers[0];

    // Поиск максимального значения
    for (int i = 1; i < size; i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
        }
    }

    int maxCount = 0;

    // Подсчет количества чисел, равных максимальному
    for (int i = 0; i < size; i++) {
        if (numbers[i] == maxValue) {
            maxCount++;
        }
    }

    return maxCount;
}
