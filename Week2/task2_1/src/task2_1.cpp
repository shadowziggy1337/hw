#include <iostream>
#include <string>
#include <ctime>

class Student {
private:
    std::string name;
    tm birthDate;
    std::string group;
    int studentId;
    float averageScore;

public:
    // Конструктор
    Student(std::string name, tm birthDate, std::string group, int studentId, float averageScore)
        : name(name), birthDate(birthDate), group(group), studentId(studentId), averageScore(averageScore) {}

    // Геттеры
    std::string getName() const { return name; }
    tm getBirthDate() const { return birthDate; }
    std::string getGroup() const { return group; }
    int getStudentId() const { return studentId; }
    float getAverageScore() const { return averageScore; }

    // Сеттеры
    void setName(std::string newName) { name = newName; }
    void setBirthDate(tm newBirthDate) { birthDate = newBirthDate; }
    void setGroup(std::string newGroup) { group = newGroup; }
    void setStudentId(int newStudentId) { studentId = newStudentId; }
    void setAverageScore(float newAverageScore) { averageScore = newAverageScore; }

    // Метод для вычисления возраста студента
    int getAge() {
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        
        int age = currentTime->tm_year + 1900 - birthDate.tm_year;
        if (birthDate.tm_mon > currentTime->tm_mon ||
            (birthDate.tm_mon == currentTime->tm_mon && birthDate.tm_mday > currentTime->tm_mday)) {
            age--;
        }
        
        return age;
    }

    // Метод для проверки является ли студент отличником
    bool isExcellentStudent() {
        return averageScore >= 4.8;
    }

    // Метод для вывода информации о студенте
    void toString() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birth Date: " << asctime(&birthDate);
        std::cout << "Group: " << group << std::endl;
        std::cout << "Student ID: " << studentId << std::endl;
        std::cout << "Average Score: " << averageScore << std::endl;
    }
};

int main() {
    // Создание объектов класса Student и тестирование методов
    tm birthDate = {}; // Инициализация struct tm для времени рождения (0 по умолчанию)
    birthDate.tm_year = 90; // Год
    birthDate.tm_mon = 10; // Месяц
    birthDate.tm_mday = 15; // День
    Student student1("Sasha", birthDate, "A123", 12345, 4.9);
    
    student1.toString();
    std::cout << "Age: " << student1.getAge() << std::endl;
    std::cout << "Excellent student: " << std::boolalpha << student1.isExcellentStudent() << std::endl;

    return 0;
}
