#include "../include/Book.hpp"

Book::Book(const Author& author, const std::string& title)
    : author(author), title(title) {}

Author Book::getAuthor() const {
    return author;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setAuthor(const Author& author) {
    this->author = author;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}
