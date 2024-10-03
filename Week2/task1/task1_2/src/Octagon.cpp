#include "Octagon.hpp"
#include <cmath>

Octagon::Octagon() : innerRadius(0) {}

void Octagon::setInnerRadius(double r) {
    innerRadius = r;
}

double Octagon::getInnerRadius() const {
    return innerRadius;
}

double Octagon::calculateArea() const {
    return 8 * (std::sqrt(2) - 1) * (innerRadius * innerRadius);
}

double Octagon::calculatePerimeter() const {
    return (16 * innerRadius) / (1 + std::sqrt(2));
}
