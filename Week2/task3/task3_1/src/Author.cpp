#include "../include/Author.hpp"

Author::Author(const std::string& name, int birthYear)
    : name(name), birthYear(birthYear) {}

std::string Author::getName() const {
    return name;
}

int Author::getBirthYear() const {
    return birthYear;
}

void Author::setName(const std::string& name) {
    this->name = name;
}

void Author::setBirthYear(int birthYear) {
    this->birthYear = birthYear;
}
