#include <iostream>
#include <string>

// Класс Author для хранения информации об авторе книги
class Author {
private:
    std::string name; // Имя автора
    int birthYear; // Год рождения автора

public:
    // Конструктор класса Author
    Author(const std::string& authorName, int authorBirthYear) : name(authorName), birthYear(authorBirthYear) {}

    // Методы для получения информации об авторе
    std::string getName() const {
        return name;
    }

    int getBirthYear() const {
        return birthYear;
    }

    // Методы для установки информации об авторе
    void setName(const std::string& authorName) {
        name = authorName;
    }

    void setBirthYear(int authorBirthYear) {
        birthYear = authorBirthYear;
    }
};

// Класс Book, представляющий книгу и содержащий объект Author в качестве атрибута
class Book {
private:
    std::string title; // Название книги
    Author author; // Объект автора книги

public:
    // Конструктор класса Book
    Book(const std::string& bookTitle, const Author& bookAuthor) : title(bookTitle), author(bookAuthor) {}

    // Методы для получения информации о книге и авторе
    std::string getTitle() const {
        return title;
    }

    Author getAuthor() const {
        return author;
    }

    // Методы для установки информации о книге и авторе
    void setTitle(const std::string& bookTitle) {
        title = bookTitle;
    }

    void setAuthor(const Author& bookAuthor) {
        author = bookAuthor;
    }
};

int main() {
    // Создание объекта автора и книги
    Author author("Лев Толстой", 1828);
    Book book("Война и мир", author);

    // Вывод информации о книге и авторе
    std::cout << "Название книги: " << book.getTitle() << std::endl;
    std::cout << "Автор: " << book.getAuthor().getName() << std::endl;
    std::cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << std::endl;

    // Обновление информации об авторе
    Author newAuthor("Федор Достоевский", 1821);
    book.setAuthor(newAuthor);

    // Вывод обновленной информации об авторе
    std::cout << "\nОбновленная информация об авторе:" << std::endl;
    std::cout << "Автор: " << book.getAuthor().getName() << std::endl;
    std::cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << std::endl;

    return 0;
}
