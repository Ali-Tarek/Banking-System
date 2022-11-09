#ifndef BANKING_SYSTEM_BANKACCOUNT_H
#define BANKING_SYSTEM_BANKACCOUNT_H

#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
protected:
    string ID;
    double Balance;

public:
    BankAccount();
    BankAccount(string, double);
    void setBalance(double );
    void setID(string );
    double getBalance();
    string getID();
    virtual void withdraw(double);
    virtual void deposit(double);

};


#endif //BANKING_SYSTEM_BANKACCOUNT_H
