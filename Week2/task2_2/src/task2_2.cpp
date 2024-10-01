#include <iostream>
#include <string>

class BankAccount { // Объявление класса BankAccount
private:
    std::string accountNumber; // Приватное поле для номера счета
    double balance; // Приватное поле для баланса

public:
    BankAccount(std::string accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {} // Конструктор класса для инициализации номера счета и баланса

    void deposit(double amount) { // Метод для внесения денег на счет
        if (amount > 0) { // Проверка на положительную сумму
            balance += amount; // Увеличение баланса на сумму
            std::cout << "Deposited: " << amount << std::endl; // Вывод сообщения об успешном внесении
        } else {
            std::cout << "Cannot deposit non-positive amount." << std::endl; // Вывод сообщения об ошибке при попытке внести отрицательную сумму
        }
    }

    void withdraw(double amount) { // Метод для снятия денег со счета
        if (amount > 0) { // Проверка на положительную сумму
            if (balance >= amount) { // Проверка на наличие достаточного баланса
                balance -= amount; // Уменьшение баланса на сумму
                std::cout << "Withdrawn: " << amount << std::endl; // Вывод сообщения об успешном снятии
            } else {
                std::cout << "Insufficient funds. Withdrawal failed." << std::endl; // Вывод сообщения о нехватке средств для снятия
            }
        } else {
            std::cout << "Cannot withdraw non-positive amount." << std::endl; // Вывод сообщения об ошибке при попытке снять отрицательную сумму
        }
    }

    double getBalance() { // Метод для получения текущего баланса
        return balance; // Возвращает текущий баланс
    }
};

int main() { // Основная функция программы
    BankAccount myAccount("12345", 1000.00); // Создание объекта myAccount класса BankAccount с номером счета "12345" и начальным балансом 1000.00

    std::cout << "Initial Balance: " << myAccount.getBalance() << std::endl; // Вывод начального баланса

    myAccount.deposit(500.50); // Внесение на счет 500.50
    std::cout << "Current Balance after deposit: " << myAccount.getBalance() << std::endl; // Вывод текущего баланса

    myAccount.withdraw(200.75); // Снятие со счета 200.75
    std::cout << "Current Balance after withdrawal: " << myAccount.getBalance() << std::endl; // Вывод текущего баланса

    myAccount.withdraw(1500.00); // Попытка снять больше денег, чем есть на счету
    std::cout << "Current Balance after attempting to withdraw too much: " << myAccount.getBalance() << std::endl; // Вывод текущего баланса

    return 0; // Возвращаем 0, чтобы показать успешное завершение программы
}
