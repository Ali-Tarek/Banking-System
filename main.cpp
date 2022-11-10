#include "BankAccount.h"
#include "SavingsBankAccount.h"
#include "BankingApplication.h"
int main() {
    BankingApplication app("database.txt");
    app.displayMenu();
}
