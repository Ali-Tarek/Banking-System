#include "SavingsBankAccount.h"

SavingsBankAccount::SavingsBankAccount(string id, double IntitialBalance, double MinimumBalance){

    while(IntitialBalance < MinimumBalance){
        cout << "Sorry. the intitial balance must be more than the minimum balance.\n";
        cout << "Please Enter The intitial balance =========>";
        cin >> IntitialBalance;
    }
    ID = id;
    Balance = IntitialBalance;
    MinBalance = MinimumBalance;
}

void SavingsBankAccount::setMinBalance(double MinimumBalance) {
    MinBalance = MinimumBalance;
}

double SavingsBankAccount::getMinBalance() {
    return MinBalance;
}


void SavingsBankAccount::withdraw(){
    cout << "Account ID: " << ID << '\n';
    cout << "Account Type: " << "Saving" << '\n';
    cout << "Balance: " << Balance << '\n';
    cout << "Min Balance: " << MinBalance << '\n';
    cout << "Please Enter The Amount to Withdraw =========> ";
    double amount; cin >> amount;
    while(amount > Balance || amount < MinBalance){
        cout << "Sorry. You cannot withdraw this amount.\n";
        cout << "Please Enter The Amount to Withdraw =========>";
        cin >> amount;
    }
    cout << "Thank you.\n";
    Balance -= amount;
    cout << "Account ID: " << ID << '\n';
    cout << "New Balance: " << Balance << '\n';
}

void SavingsBankAccount::deposit() {
    cout << "Account ID: " << ID << '\n';
    cout << "Account Type: " << "Saving" << '\n';
    cout << "Balance: " << Balance << '\n';
    cout << "Min Balance: " << MinBalance << '\n';
    cout << "Please Enter The Amount to Withdraw =========> ";
    double amount; cin >> amount;
    while(amount < 100){
        cout << "Sorry. You cannot deposit less 100 L.E.\n";
        cout << "Please Enter The Amount you want to deposit =========>";
        cin >> amount;
    }
    Balance += amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << ID << '\n';
    cout << "New Balance: " << Balance << '\n';

}

void SavingsBankAccount::writeToFile(ofstream& file){
    file << 2 << " " << BankAccount::getID() << " " << BankAccount::getBalance() << " " << MinBalance << '\n';
}

void SavingsBankAccount::printInfo(){
    cout << "Account ID: " << ID << " (Saving)\n";
    cout << "Balance: " << Balance << '\n'; 
    cout << "Min Balance: " << MinBalance << '\n';
}