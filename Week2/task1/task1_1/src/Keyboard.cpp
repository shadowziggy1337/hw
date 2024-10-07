#include "Keyboard.hpp"

void Keyboard::set_data(double p, const std::string& t) {
    price = p;
    type = t;
}

void Keyboard::get_info() const {
    std::cout << "Type: " << type << ". Price: $" << price << std::endl;
}
