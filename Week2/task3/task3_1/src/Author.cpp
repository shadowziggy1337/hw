#include "Author.hpp"

// Конструктор класса Author, инициализирующий имя автора и год его рождения
Author::Author(const std::string& name, int birthYear)
    : name(name), birthYear(birthYear) {} // Инициализация членов name и birthYear

std::string Author::getName() const {
    return name; // Возвращает имя автора
}

int Author::getBirthYear() const {
    return birthYear; // Возвращает год рождения автора
}

void Author::setName(const std::string& name) {
    this->name = name; // Устанавливает новое имя автора
}

void Author::setBirthYear(int birthYear) {
    this->birthYear = birthYear; // Устанавливает новый год рождения автора
}
