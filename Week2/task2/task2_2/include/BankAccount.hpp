#include <string>

class BankAccount {
private:
    std::string номерСчета;
    double баланс;

public:
    BankAccount(const std::string &accNum);
    
    void положить(double сумма);
    void снять(double сумма);
    double получитьБаланс() const;
};