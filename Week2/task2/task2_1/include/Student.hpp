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
    Student(std::string name, tm birthDate, std::string group, int studentId, float averageScore);

    // Методы для установки и получения значения имени студента
    void setName(std::string name);                // Установка имени
    std::string getName();                         // Получение имени

    // Методы для установки и получения даты рождения студента
    void setBirthDate(tm birthDate);               // Установка даты рождения
    tm getBirthDate();                             // Получение даты рождения

    // Методы для установки и получения группы студента
    void setGroup(std::string group);              // Установка группы
    std::string getGroup();                        // Получение группы

    // Методы для установки и получения идентификатора студента
    void setStudentId(int studentId);              // Установка идентификатора
    int getStudentId();                            // Получение идентификатора

    // Методы для установки и получения среднего балла студента
    void setAverageScore(float averageScore);      // Установка среднего балла
    float getAverageScore();                       // Получение среднего балла

    // Метод для вычисления возраста студента
    int getAge();                                  // Возвращает возраст студента в годах

    // Метод для проверки, является ли студент отличником
    bool isExcellentStudent();                      // Возвращает true, если средний балл >= 4.8

    // Метод для вывода информации о студенте
    void toString();                               // Выводит данные о студенте на экран
};
