#ifndef AUTHOR_HPP // Проверяем, определен ли AUTHOR_HPP
#define AUTHOR_HPP // Если не определен, определяем его

#include <string> // Подключаем библиотеку для работы со строками

// Объявление класса Author
class Author {
private:
    std::string name; // Имя автора
    int birthYear;    // Год рождения автора

public:
    // Конструктор класса Author, принимает имя и год рождения
    Author(const std::string& name, int birthYear);

    // Метод для получения имени автора
    std::string getName() const;

    // Метод для получения года рождения автора
    int getBirthYear() const;

    // Метод для установки имени автора
    void setName(const std::string& name);

    // Метод для установки года рождения автора
    void setBirthYear(int birthYear);
};

#endif // Завершение блока условной компиляции для AUTHOR_HPP
