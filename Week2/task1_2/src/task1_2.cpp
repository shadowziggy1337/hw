#include <iostream>
#include <cmath>

class Octagon {
private:
    double innerRadius; // Внутренний радиус восьмиугольника

public:
    void setInnerRadius(double radius) { // Метод для установки внутреннего радиуса
        innerRadius = radius;
    }

    double calculateArea() { // Метод для вычисления площади восьмиугольника
        double sideLength = 2 * innerRadius * tan(M_PI / 8); // Вычисление длины стороны
        double area = 2 * innerRadius * sideLength; // Вычисление площади
        return area;
    }

    double calculatePerimeter() { // Метод для вычисления периметра восьмиугольника
        double sideLength = 2 * innerRadius * tan(M_PI / 8); // Вычисление длины стороны
        double perimeter = 8 * sideLength; // Вычисление периметра
        return perimeter;
    }
};

int main() {
    Octagon myOctagon; // Создание объекта класса Octagon

    myOctagon.setInnerRadius(5.0); // Установка внутреннего радиуса

    // Вывод площади и периметра восьмиугольника
    std::cout << "Площадь восьмиугольника: " << myOctagon.calculateArea() << std::endl;
    std::cout << "Периметр восьмиугольника: " << myOctagon.calculatePerimeter() << std::endl;

    return 0; // Возврат нуля, указывающего на успешное завершение программы
}
