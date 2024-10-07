#include "Author.hpp"
#include <string>

class Book {
private:
    Author author;
    std::string title;

public:
    Book(const Author& author, const std::string& title);

    Author getAuthor() const;
    std::string getTitle() const;
    void setAuthor(const Author& author);
    void setTitle(const std::string& title);
};

