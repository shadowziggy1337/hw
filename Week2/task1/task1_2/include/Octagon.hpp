#ifndef OCTAGON_HPP
#define OCTAGON_HPP

class Octagon {
private:
    double innerRadius;

public:
    Octagon();   // Конструктор
    void setInnerRadius(double r);
    double getInnerRadius() const;
    double calculateArea() const;
    double calculatePerimeter() const;
};

#endif
