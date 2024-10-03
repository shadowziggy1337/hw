#include "User.hpp"

// Конструктор по умолчанию
Person::Person() {
    name = "Егор";
    age = 22;
}

// Конструктор с параметрами
Person::Person(const std::string& n, int a) {
    name = n;
    age = a;
}

// Геттер имени
std::string Person::getName() const {
    return name;
}

// Геттер возраста
int Person::getAge() const {
    return age;
}

// Сеттер имени
void Person::setName(const std::string& n) {
    name = n;
}

// Сеттер возраста
void Person::setAge(int a) {
    age = a;
}