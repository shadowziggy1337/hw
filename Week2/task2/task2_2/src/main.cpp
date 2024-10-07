#include <iostream>
#include "BankAccount.hpp"

int main() {
    BankAccount account("123456789");
    int choice;

    do {
        std::cout << "\n---------- Menu ----------" << std::endl;
        std::cout << "1. Deposit money" << std::endl;
        std::cout << "2. Withdraw money" << std::endl;
        std::cout << "3. View balance" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Enter the amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                std::cout << "Amount added to account: " << amount << " rub." << std::endl;
                break;
            }
            case 2: {
                double amount;
                std::cout << "Enter the amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3: {
                std::cout << "Current balance: " << account.getBalance() << " rub." << std::endl;
                break;
            }
            case 0:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
