#include <iostream>
#include <list>
#include "../include/maxProfit.hpp"

using namespace std;

int main() {
    // Предопределенный список цен акций
    list<int> prices = {7, 1, 5, 3, 6, 4};

    int profit = maxProfit(prices); // Вычисляем максимальную прибыль
    cout << "Максимальная прибыль: " << profit << endl; // Выводим результат

    return 0; // Завершаем программу
}
