#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount(string id, double IntitialBalance, double MinimumBalance) : BankAccount(id, IntitialBalance) {

    while(IntitialBalance < MinimumBalance){
        cout << "Sorry. the intitial balance must be more than the minimum balance.\n";
        cout << "Please Enter The intitial balance =========>";
        cin >> IntitialBalance;
    }

    Balance = IntitialBalance;
    MinBalance = MinimumBalance;
}

void SavingsBankAccount::setMinBalance(double MinimumBalance) {
    MinBalance = MinimumBalance;
}

double SavingsBankAccount::getMinBalance() {
    return MinBalance;
}


void SavingsBankAccount::withdraw(double amount){

    while(amount > Balance || amount < MinBalance){
        cout << "Sorry. You cannot withdraw this amount.\n";
        cout << "Please Enter The Amount to Withdraw =========>";
        cin >> amount;
    }
    Balance -= amount;
}

void SavingsBankAccount::deposit(double amount) {
    while(amount < 100){
        cout << "Sorry. You cannot deposit less 100 L.E.\n";
        cout << "Please Enter The Amount you want to deposit =========>";
        cin >> amount;
    }

//    BankAccount::deposit(amount);
    Balance += amount;
}

