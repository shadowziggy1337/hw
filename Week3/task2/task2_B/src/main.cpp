#include "heron.hpp"
#include <iostream>
using namespace std;

int main() {
    double number;
    cout << "Введите число: ";
    cin >> number;
    double sqrt = Heron (number);
    cout << "Квадратный корень из " << number << " равен " << sqrt << endl;
    return 0;
}