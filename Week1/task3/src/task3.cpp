#include <iostream>
#include <cmath>

int main() {
    double a, volume;

    // Запрашиваем у пользователя длину ребра икосаэдра
    std::cout << "Введите длину ребра икосаэдра: ";
    std::cin >> a;

    // Вычисляем объем икосаэдра
    volume = (5.0 / 12.0) * (3 + sqrt(5)) * pow(a, 3);

    // Выводим промежуточные расчеты и результат
    std::cout << "Промежуточные расчеты:\n";
    std::cout << "Сторона в кубе: " << pow(a, 3) << std::endl;
    std::cout << "Коэффициент икосаэдра: " << (5.0 / 12.0) * (3 + sqrt(5)) << std::endl;
    std::cout << "Объем икосаэдра: " << volume << std::endl;

    return 0;
}
