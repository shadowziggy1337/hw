#include <string>

class Author {
private:
    std::string name;
    int birthYear;

public:
    Author(const std::string& name, int birthYear);

    std::string getName() const;
    int getBirthYear() const;
    void setName(const std::string& name);
    void setBirthYear(int birthYear);
};
