#include "BankAccount.h"
#include "SavingsBankAccount.h"

int main() {

    SavingsBankAccount user("Ali", 1500, 1000);
    cout << user.getID() << " " << user.getBalance() << " " << user.getMinBalance() << '\n';
    user.setID("Ahmed");
    user.setBalance(2000);
    user.setMinBalance(1500);
    cout << user.getID() << " " << user.getBalance() << " " << user.getMinBalance() << '\n';
    user.withdraw(500);
    cout << user.getID() << " " << user.getBalance() << " " << user.getMinBalance() << '\n';
    user.deposit(1800);
    cout << user.getID() << " " << user.getBalance() << " " << user.getMinBalance() << '\n';

}
