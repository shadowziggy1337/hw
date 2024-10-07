#include <iostream>
#include "Student.hpp"

int main() {
    std::tm birthDate1 = {};
    birthDate1.tm_year = 2002 - 1900;
    birthDate1.tm_mon = 7;
    birthDate1.tm_mday = 11;

    Student student1("Ларионов Егор", birthDate1, "Группа 23ИБ1б", 1337, 5.0f);

    std::tm birthDate2 = {};
    birthDate2.tm_year = 1999 - 1900;
    birthDate2.tm_mon = 4;
    birthDate2.tm_mday = 3;

    Student student2("Семенов Алексей", birthDate2, "Группа 19ОД2д", 1282, 3.0f);

    std::cout << "Студент 1:\n";
    std::cout << student1.toString() << std::endl;
    std::cout << "Возраст: " << student1.getAge() << " лет" << std::endl;
    std::cout << "Отличник: " << (student1.isExcellentStudent() ? "Да" : "Нет") << std::endl;

    std::cout << std::endl;

    std::cout << "Студент 2:\n";
    std::cout << student2.toString() << std::endl;
    std::cout << "Возраст: " << student2.getAge() << " лет" << std::endl;
    std::cout << "Отличник: " << (student2.isExcellentStudent() ? "Да" : "Нет") << std::endl;

    return 0;
}