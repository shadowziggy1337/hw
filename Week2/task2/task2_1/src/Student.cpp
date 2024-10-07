#include "Student.hpp"
#include <iostream>
#include <ctime> 

// Конструктор класса Student
Student::Student(std::string name, tm birthDate, std::string group, int studentId, float averageScore)
    : name(name), birthDate(birthDate), group(group), studentId(studentId), averageScore(averageScore) {}

// Метод для установки имени студента
void Student::setName(std::string name) {
    this->name = name; // Присваиваем значение параметра полю объекта
}

// Метод для получения имени студента
std::string Student::getName() {
    return name; // Возвращаем значение имени
}

// Метод для установки даты рождения студента
void Student::setBirthDate(tm birthDate) {
    this->birthDate = birthDate; // Присваиваем значение параметра полю объекта
}

// Метод для получения даты рождения студента
tm Student::getBirthDate() {
    return birthDate; // Возвращаем значение даты рождения
}

// Метод для установки группы студента
void Student::setGroup(std::string group) {
    this->group = group; // Присваиваем значение параметра полю объекта
}

// Метод для получения группы студента
std::string Student::getGroup() {
    return group; // Возвращаем значение группы
}

// Метод для установки идентификатора студента
void Student::setStudentId(int studentId) {
    this->studentId = studentId; // Присваиваем значение параметра полю объекта
}

// Метод для получения идентификатора студента
int Student::getStudentId() {
    return studentId; // Возвращаем значение идентификатора
}

// Метод для установки среднего балла студента
void Student::setAverageScore(float averageScore) {
    this->averageScore = averageScore; // Присваиваем значение параметра полю объекта
}

// Метод для получения среднего балла студента
float Student::getAverageScore() {
    return averageScore; // Возвращаем значение среднего балла
}

// Метод для вычисления возраста студента
int Student::getAge() {
    time_t now; // Переменная для хранения текущего времени
    time(&now); // Получаем текущее время
    tm* currentTime = localtime(&now); // Преобразуем в структуру tm для удобной работы с датой
    int currentYear = currentTime->tm_year + 1900; // Получаем текущий год
    int birthYear = birthDate.tm_year + 1900; // Получаем год рождения студента
    return currentYear - birthYear; // Возвращаем разность, которая равна возрасту
}

// Метод для проверки, является ли студент отличником
bool Student::isExcellentStudent() {
    return averageScore >= 4.8; // Возвращаем true, если средний балл равен или превышает 4.8
}

// Метод для вывода информации о студенте
void Student::toString() {
    std::cout << "Name: " << name << std::endl; // Вывод имени студента
    std::cout << "Birth Date: " << asctime(&birthDate); // Вывод даты рождения в формате строки
    std::cout << "Group: " << group << std::endl; // Вывод группы студента
    std::cout << "Student ID: " << studentId << std::endl; // Вывод идентификатора студента
    std::cout << "Average Score: " << averageScore << std::endl; // Вывод среднего балла
}
