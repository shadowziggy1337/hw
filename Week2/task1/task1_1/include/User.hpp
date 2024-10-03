#ifndef USER_HPP
#define USER_HPP

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person();
    Person(const std::string& n, int a);
    std::string getName() const;
    int getAge() const;
    void setName(const std::string& n);
    void setAge(int a);
};

#endif