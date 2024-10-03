#include <iostream>
#include <string>
#include "Car.hpp"
#include "Engine.hpp"
#include "Passenger.hpp"

int main() {
    Engine engine("V6");
    Car car("Toyota Mark 2", engine);

    std::string name1, name2, nameToRemove;

    std::cout << "Введите имя первого пассажира: ";
    std::getline(std::cin, name1);
    car.addPassenger(Passenger(name1));

    std::cout << "Введите имя второго пассажира: ";
    std::getline(std::cin, name2);
    car.addPassenger(Passenger(name2));

    std::cout << "Введите имя пассажира, которого хотите удалить: ";
    std::getline(std::cin, nameToRemove);
    car.removePassenger(nameToRemove);

    car.displayInfo();

    return 0;
}
