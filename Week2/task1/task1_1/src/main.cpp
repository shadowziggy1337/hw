#include <iostream>
#include <locale>
#include "Keyboard.hpp"

int main() {
    setlocale(LC_ALL, "RU");

    Keyboard mechanical;
    mechanical.set_data(50.0, "Mechanical keyboard");
    mechanical.get_info();

    Keyboard membrane;
    membrane.set_data(5.0, "Membrane keyboard");
    membrane.get_info();

    return 0;
}
