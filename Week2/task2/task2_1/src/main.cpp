#include <iostream>
#include <ctime>
#include "Student.hpp"

int main() {
    struct tm birthDate1 = {1, 2, 3, 11, 8, 102};
    struct tm birthDate2 = {1, 2, 3, 7, 3, 102};

    Student student1("Egor", birthDate1, "23ib1b", 12345, 4.9);
    
    Student student2("Sasha", birthDate2, "23id1d", 54321, 4.7);

    student1.toString();
    std::cout << "Age: " << student1.getAge() << " years" << std::endl; // Вывод возраста студента
    std::cout << "Is student1 an excellent student? " // Проверка, является ли первый студент отличником
              << (student1.isExcellentStudent() ? "Yes" : "No") << std::endl;

    std::cout << std::endl;

    student2.toString(); // Вывод данных студента
    std::cout << "Age: " << student2.getAge() << " years" << std::endl; // Вывод возраста студента
    std::cout << "Is student2 an excellent student? " // Проверка, является ли второй студент отличником
              << (student2.isExcellentStudent() ? "Yes" : "No") << std::endl;

    return 0;
}
