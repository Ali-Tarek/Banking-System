#ifndef BANKING_SYSTEM_BANKINGAPPLICATION_H
#define BANKING_SYSTEM_BANKINGAPPLICATION_H

#include "client.h"

class BankingApplication {
    vector<client>clients;
    int idCounter;
    string File;
    void load();
    void save();
public:
    BankingApplication(string);
    void addClient();
    void withdrawMoney();
    void depositMoney();
    void listAllClientsAndAccounts();
    void displayMenu();
    ~BankingApplication();

};


#endif //BANKING_SYSTEM_BANKINGAPPLICATION_H
