#include <iostream>
#include <string>

class Keyboard {
private:
    double price;
    std::string type;

public:
    void set_data(double p, const std::string& t);
    void get_info() const;
};

