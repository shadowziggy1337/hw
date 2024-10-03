#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <vector>
#include "Engine.hpp"
#include "Passenger.hpp"

class Car {
private:
    std::string model;
    Engine engine;
    std::vector<Passenger> passengers;

public:
    Car(const std::string &model, const Engine &engine);
    void addPassenger(const Passenger &passenger);
    void removePassenger(const std::string &name);
    void displayInfo() const;
};

#endif // CAR_HPP
