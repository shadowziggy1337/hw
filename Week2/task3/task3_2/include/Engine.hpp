#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>

class Engine {
private:
    std::string type;

public:
    Engine(const std::string &type);
    std::string getType() const;
};

#endif
