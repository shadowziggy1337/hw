#include <iostream>
#include <string>
#include <vector>

// Класс, представляющий двигатель автомобиля
class Engine {
private:
    int power; // Мощность двигателя

public:
    Engine(int power) : power(power) {}

    // Метод для получения мощности двигателя
    int getPower() {
        return power;
    }
};

// Класс, представляющий пассажира автомобиля
class Passenger {
private:
    std::string name; // Имя пассажира

public:
    Passenger(std::string name) : name(name) {}

    // Метод для получения имени пассажира
    std::string getName() {
        return name;
    }
};

// Класс, представляющий автомобиль
class Car {
private:
    std::string model; // Модель автомобиля
    Engine engine; // Ссылка на объект типа Engine
    Passenger* passenger1; // Пассажир 1
    Passenger* passenger2; // Пассажир 2

public:
    Car(std::string model, Engine engine) : model(model), engine(engine), passenger1(nullptr), passenger2(nullptr) {}

    // Метод для добавления пассажира
    void addPassenger(Passenger* passenger) {
        if (passenger1 == nullptr) {
            passenger1 = passenger;
        } else if (passenger2 == nullptr) {
            passenger2 = passenger;
        } else {
            std::cout << "Car is full, cannot add more passengers." << std::endl;
        }
    }

    // Метод для удаления пассажира
    void removePassenger(Passenger* passenger) {
        if (passenger1 == passenger) {
            passenger1 = nullptr;
        } else if (passenger2 == passenger) {
            passenger2 = nullptr;
        } else {
            std::cout << "Passenger not found in the car." << std::endl;
        }
    }

    // Метод для вывода информации об автомобиле и его пассажирах
    void displayInfo() {
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Engine Power: " << engine.getPower() << std::endl;
        
        if (passenger1 != nullptr) {
            std::cout << "Passenger 1: " << passenger1->getName() << std::endl;
        }
        
        if (passenger2 != nullptr) {
            std::cout << "Passenger 2: " << passenger2->getName() << std::endl;
        }
    }
};

int main() {
    // Создание объекта двигателя и автомобиля
    Engine carEngine(200);
    Car car("Toyota Camry", carEngine);
    
    // Создание и добавление пассажиров
    Passenger passenger1("Alice");
    car.addPassenger(&passenger1);
    
    Passenger passenger2("Bob");
    car.addPassenger(&passenger2);
    
    // Вывод информации об автомобиле
    car.displayInfo();
    
    // Удаление пассажира и повторный вывод информации
    car.removePassenger(&passenger1);
    car.displayInfo();
    
    return 0;
}

