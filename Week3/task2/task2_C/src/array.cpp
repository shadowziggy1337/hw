#include "array.hpp"
#include <iostream>

void sieveOfEratosthenes(int n) {
    bool* isPrime = new bool[n + 1];
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    // Применяем алгоритм решета Эратосфена
    for (int p = 2; p * p <= n; p++) {
        // Если число не помечено как составное, значит, оно простое
        if (isPrime[p]) {
            // Помечаем все кратные числа как составные
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Выводим простые числа
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            std::cout << p << " ";
        }
    }

    delete[] isPrime;
}
