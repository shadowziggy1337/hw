#include <iostream>
#include <string>
#include "Author.hpp"
#include "Book.hpp"

int main() {
    Author author("Пушкин Александр", 1799);

    Book book(author, "Евгений Онегин"); 

    int choice; // Переменная для хранения выбора пользователя

    // Выводим имя автора книги
    std::cout << "Автор: " << book.getAuthor().getName() << std::endl;
    std::cout << "Что вы хотите узнать об авторе?" << std::endl;

    // Предлагаем пользователю выбрать, что он хочет узнать
    std::cout << "1. Название книги" << std::endl;
    std::cout << "2. Год рождения" << std::endl;
    std::cout << "Введите номер вашего выбора (1 или 2): ";

    // Считываем выбор пользователя
    std::cin >> choice;

    // Проверяем выбор пользователя и выводим соответствующую информацию
    if (choice == 1) {
        std::cout << "Книга: " << book.getTitle() << std::endl; // Выводим название книги
    } else if (choice == 2) {
        std::cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << std::endl; // Выводим год рождения автора
    } else {
        // Если выбрано неверное значение, выводим сообщение об ошибке
        std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2." << std::endl;
    }

    return 0; // Завершаем программу
}
