#include "BankAccount.hpp"
#include <iostream>

BankAccount::BankAccount(const std::string &accNum)
    : accountNumber(accNum), balance(0.0) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "The deposit amount must be positive!" << std::endl;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Insufficient funds or incorrect withdrawal amount!" << std::endl;
    }
}

double BankAccount::getBalance() const {
    return balance;
}
