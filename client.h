#ifndef BANKING_SYSTEM_CLIENT_H
#define BANKING_SYSTEM_CLIENT_H
#include "BankAccount.h"
#include <bits/stdc++.h>

using namespace std;
class client
{
private:
    string Name, Address, Phone;
    shared_ptr<BankAccount>account;
public:
    client(string = "", string = "", string = "");
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    string getName();
    string getAddress();
    string getPhone();
    void setAccount(shared_ptr<BankAccount>);
    shared_ptr<BankAccount> getAccount();

};


#endif //BANKING_SYSTEM_CLIENT_H
