#include "merge_sort.hpp"

// Слияние двух подмассивов
void merge(double arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Создаем временные массивы
    double tempLeft[n1], tempRight[n2];

    // Копируем данные во временные массивы
    for (i = 0; i < n1; i++)
        tempLeft[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        tempRight[j] = arr[middle + 1 + j];

    // Слияние временных массивов обратно в основной массив
    i = 0;  // Индекс первого подмассива
    j = 0;  // Индекс второго подмассива
    k = left;  // Индекс сливаемого подмассива

    while (i < n1 && j < n2) {
        if (tempLeft[i] <= tempRight[j]) {
            arr[k] = tempLeft[i];
            i++;
        } else {
            arr[k] = tempRight[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы tempLeft[], если таковые имеются
    while (i < n1) {
        arr[k] = tempLeft[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы tempRight[], если таковые имеются
    while (j < n2) {
        arr[k] = tempRight[j];
        j++;
        k++;
    }
}

// Главная функция сортировки слиянием
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        // Находим среднюю точку
        int middle = left + (right - left) / 2;

        // Рекурсивно сортируем две половины
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Сливаем два отсортированных подмассива
        merge(arr, left, middle, right);
    }
}
