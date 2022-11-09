#ifndef BANKING_SYSTEM_CLIENT_H
#define BANKING_SYSTEM_CLIENT_H
#include "BankAccount.h"
#include <bits/stdc++.h>

using namespace std;
class client
{
private:
    string Name, Address, Phone;
    BankAccount* Acc = nullptr;
public:
    client(string = "", string = "", string = "");
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    string getName();
    string getAddress();
    string getPhone();

};


#endif //BANKING_SYSTEM_CLIENT_H
