#include "Student.hpp"
#include <sstream>
#include <chrono>

#include "Student.hpp"

Student::Student(std::string name, std::tm birthDate, std::string group, int studentId, float averageScore)
    : name(std::move(name)), birthDate(birthDate), group(std::move(group)), studentId(studentId), averageScore(averageScore) {}

std::string Student::getName() { return name; }
std::tm Student::getBirthDate() { return birthDate; }
std::string Student::getGroup() { return group; }
int Student::getStudentId() { return studentId; }
float Student::getAverageScore() { return averageScore; }

void Student::setName(const std::string& newName) { name = newName; }
void Student::setBirthDate(const std::tm& newBirthDate) { birthDate = newBirthDate; }
void Student::setGroup(const std::string& newGroup) { group = newGroup; }
void Student::setStudentId(int newStudentId) { studentId = newStudentId; }
void Student::setAverageScore(float newAverageScore) { averageScore = newAverageScore; }

int Student::getAge() {
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    int age = now_tm->tm_year - birthDate.tm_year;
    if (now_tm->tm_mon < birthDate.tm_mon || (now_tm->tm_mon == birthDate.tm_mon && now_tm->tm_mday < birthDate.tm_mday)) {
        age--;
    }
    return age;
}

std::string Student::toString() {
    std::ostringstream oss;
    oss << "Имя: " << name << "\n"
        << "Дата рождения: " << std::put_time(&birthDate, "%Y-%m-%d") << "\n"
        << "Группа: " << group << "\n"
        << "Студенческий ID: " << studentId << "\n"
        << "Средний балл: " << averageScore;
    return oss.str();
}

bool Student::isExcellentStudent() {
    return averageScore = 5.0f;
}
