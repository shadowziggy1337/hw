#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Student {
private:
    std::string name;
    std::tm birthDate;
    std::string group;
    int studentId;
    float averageScore;

public:
    Student(std::string name, std::tm birthDate, std::string group, int studentId, float averageScore);
    std::string getName();
    std::tm getBirthDate();
    std::string getGroup();
    int getStudentId();
    float getAverageScore();

    void setName(const std::string& newName);
    void setBirthDate(const std::tm& newBirthDate);
    void setGroup(const std::string& newGroup);
    void setStudentId(int newStudentId);
    void setAverageScore(float newAverageScore);

    int getAge();
    std::string toString();
    bool isExcellentStudent();
};

#endif