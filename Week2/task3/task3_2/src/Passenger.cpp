#include "Passenger.hpp"

Passenger::Passenger(const std::string &name) : name(name) {}

std::string Passenger::getName() const {
    return name;
}
