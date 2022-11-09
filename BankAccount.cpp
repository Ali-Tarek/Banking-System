#include "BankAccount.h"

BankAccount::BankAccount() : Balance(0) {}

BankAccount::BankAccount(string id, double balance) : ID(id), Balance(balance) {}

void BankAccount::setBalance(double balance) {
    Balance = balance;
}

void BankAccount::setID(string id) {
    ID = id;
}

double BankAccount::getBalance() {
    return Balance;
}

string BankAccount::getID() {
    return ID;
}

void BankAccount::withdraw(double amount) {
    while(amount > Balance){
        cout << "Sorry. This is more than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw =========>";
        cin >> amount;
    }
    Balance -= amount;

}

void BankAccount::deposit(double amount) {
    Balance += amount;
}



