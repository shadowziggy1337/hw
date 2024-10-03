#include <iostream>
#include "Octagon.hpp"

int main() {
    Octagon octagon;
    octagon.setInnerRadius(5.0);

    std::cout << "Inner Radius: " << octagon.getInnerRadius() << std::endl;
    std::cout << "Area: " << octagon.calculateArea() << std::endl;
    std::cout << "Perimeter: " << octagon.calculatePerimeter() << std::endl;

    return 0;
}
