#include "median.hpp"
#include "bubblesort.hpp"

void findMedian(double arr[], int size, double& median) {
    bubbleSort(arr, size);

    if (size % 2 == 1) {
        median = arr[size / 2];
    } else {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}
