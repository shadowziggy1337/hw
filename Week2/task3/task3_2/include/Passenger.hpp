#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>

class Passenger {
private:
    std::string name;

public:
    Passenger(const std::string &name);
    std::string getName() const;
};

#endif // PASSENGER_HPP
