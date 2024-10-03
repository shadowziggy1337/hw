#include "BankAccount.hpp"
#include <iostream>

BankAccount::BankAccount(const std::string &accNum)
    : номерСчета(accNum), баланс(0.0) {}

void BankAccount::положить(double сумма) {
    if (сумма > 0) {
        баланс += сумма;
    } else {
        std::cerr << "Сумма депозита должна быть положительной!" << std::endl;
    }
}

void BankAccount::снять(double сумма) {
    if (сумма > 0 && сумма <= баланс) {
        баланс -= сумма;
    } else {
        std::cerr << "Недостаточно средств или неверная сумма снятия!" << std::endl;
    }
}

double BankAccount::получитьБаланс() const {
    return баланс;
}
