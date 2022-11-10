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

void BankAccount::withdraw() {
    cout << "Account ID: " << ID << '\n';
    cout << "Account Type: " << "Basic" << '\n';
    cout << "Balance: " << Balance << '\n';
    cout << "Please Enter The Amount to Withdraw =========> ";
    double amount; cin >> amount;
    while(amount > Balance){
        cout << "Sorry. This is more than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw =========> ";
        cin >> amount;
    }
    cout << "Thank you.\n";
    Balance -= amount;
    cout << "Account ID: " << ID << '\n';
    cout << "New Balance: " << Balance << '\n';

}

void BankAccount::deposit(){
    cout << "Account ID: " << ID << '\n';
    cout << "Account Type: " << "Basic" << '\n';
    cout << "Balance: " << Balance << '\n';
    cout << "Please Enter The Amount to deposit =========> ";
    double amount; cin >> amount;
    cout << "Thank you.\n";
    Balance += amount;
    cout << "Account ID: " << ID << '\n';
    cout << "New Balance: " << Balance << '\n';
}

void BankAccount::writeToFile(ofstream& file){
    file << 1 << " " << ID << " " << Balance << '\n';
}

void BankAccount::printInfo(){
    cout << "Account ID: " << ID << " (Basic)\n";
    cout << "Balance: " << Balance << '\n'; 
}


