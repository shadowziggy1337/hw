#ifndef BOOK_HPP // Проверяем, определен ли BOOK_HPP
#define BOOK_HPP // Если не определен, определяем его

#include "Author.hpp" // Подключаем заголовочный файл Author
#include <string> // Подключаем библиотеку для работы со строками

// Объявление класса Book
class Book {
private:
    Author author;      // Объект класса Author, представляющий автора книги
    std::string title;  // Название книги

public:
    // Конструктор класса Book, принимает ссылку на автора и название книги
    Book(const Author& author, const std::string& title);

    // Метод для получения автора книги
    Author getAuthor() const;

    // Метод для получения названия книги
    std::string getTitle() const;

    // Метод для установки автора книги
    void setAuthor(const Author& author);

    // Метод для установки названия книги
    void setTitle(const std::string& title);
};

#endif // Завершение блока условной компиляции для BOOK_HPP
