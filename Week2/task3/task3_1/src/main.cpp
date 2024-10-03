#include <iostream>
#include <string>
#include "../include/Author.hpp"
#include "../include/Book.hpp"

int main() {
    Author author("Пушкин Александр", 1799);
    Book book(author, "Евгений Онегин"); 

    int choice;

    std::cout << "Автор: " << book.getAuthor().getName() << std::endl;
    std::cout << "Что вы хотите узнать об авторе?" << std::endl;
    std::cout << "1. Название книги" << std::endl;
    std::cout << "2. Год рождения" << std::endl;
    std::cout << "Введите номер вашего выбора (1 или 2): ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Книга: " << book.getTitle() << std::endl;
    } else if (choice == 2) {
        std::cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << std::endl;
    } else {
        std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2." << std::endl;
    }

    return 0;
}
