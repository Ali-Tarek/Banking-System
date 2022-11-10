/*
 * FCAI – Object-Oriented Programming 1 – 2022 - Assignment 2
 * Program Name: Bank Ssytem
 * Last Modification Date: 10/11/2022
 * Author and ID:
 * Ali Tarek Mohamed Amin  ID: 20210245
 * Mohamed Wael ID: 20210361
 * Youssif Ezzat ID: 20210688
 */
#include "BankAccount.h"
#include "SavingsBankAccount.h"
#include "BankingApplication.h"
int main() {
    BankingApplication app("database.txt");
    int run = 1;
    while(run) {
        app.displayMenu();
        cout << "Enter 1 for continue or 0 for Exit ===>";
        cin >> run;
    }
}
