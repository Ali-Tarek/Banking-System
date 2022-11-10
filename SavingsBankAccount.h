#ifndef BANKING_SYSTEM_SAVINGSBANKACCOUNT_H
#define BANKING_SYSTEM_SAVINGSBANKACCOUNT_H

#include "BankAccount.h"

class SavingsBankAccount : public BankAccount
{
private:
    double MinBalance;
public:
    SavingsBankAccount(string id, double IntitialBalance, double MinimumBalance = 1000);
    void setMinBalance(double );
    double getMinBalance();
    void withdraw();
    void deposit();
    void writeToFile(ofstream&);
    void printInfo();

};


#endif //BANKING_SYSTEM_SAVINGSBANKACCOUNT_H
