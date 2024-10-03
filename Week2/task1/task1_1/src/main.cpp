#include <iostream>
#include "User.hpp"

int main() {
    Person person1; // Создание объекта person1 с использованием конструктора по умолчанию
    std::cout << "Человек 1:" << std::endl;
    std::cout << "Имя: " << person1.getName() << std::endl;
    std::cout << "Возраст: " << person1.getAge() << std::endl;

    Person person2("Анна", 25); // Создание объекта person2
    std::cout << "\nЧеловек 2:" << std::endl;
    std::cout << "Имя: " << person2.getName() << std::endl;
    std::cout << "Возраст: " << person2.getAge() << std::endl;

    person1.setName("Петр");
    person1.setAge(30);
    std::cout << "\nОбновленные данные для Человека 1:" << std::endl;
    std::cout << "Имя: " << person1.getName() << std::endl;
    std::cout << "Возраст: " << person1.getAge() << std::endl;

    return 0;
}