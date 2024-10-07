#include "Book.hpp"

Book::Book(const Author& author, const std::string& title)
    : author(author), title(title) {} // Инициализация членов author и title

Author Book::getAuthor() const {
    return author; // Возвращает объект автора, написавшего книгу
}

std::string Book::getTitle() const {
    return title; // Возвращает название книги
}

void Book::setAuthor(const Author& author) {
    this->author = author; // Устанавливает нового автора для книги
}

void Book::setTitle(const std::string& title) {
    this->title = title; // Устанавливает новое название для книги
}
