#include "BankingApplication.h"
#include "SavingsBankAccount.h"

BankingApplication::BankingApplication(string file){
    File = file;
    load();
}

BankingApplication::~BankingApplication(){
    save();
}

void BankingApplication::load(){
    ifstream file(File);
    if(!file){
        cout << "Can not open " << File << '\n';
        return;
    }
    string cnt = "0";
    getline(file, cnt);
    if(cnt == "0"){
        cnt = "1";
    }
    if(!cnt.empty())
        idCounter = stoi(cnt);
    else
        idCounter = 1;
    while(!file.eof()){
        string name, address, phone;
        getline(file, name);
        if(name.empty()){
            break;
        }
        getline(file, address);
        getline(file, phone);
        client c(name, address, phone);
        string type;
        getline(file, type);
        shared_ptr<BankAccount>account;
        if(type == "1"){ //basic
            string id, balance;
            getline(file, id);
            getline(file, balance);
            account = make_shared<BankAccount>(id, stod(balance));
        }else{// saving
            string id, balance, minBalance;
            getline(file, id);
            getline(file, balance);
            getline(file, minBalance);
            account = make_shared<SavingsBankAccount>(id, stod(balance), stod(minBalance));
        }
        c.setAccount(account);
        clients.push_back(c);
    }
    file.close();
}

void BankingApplication::save(){
    ofstream file(File);
    if(!file){
        cout << "Can not open" << File << '\n';
        return;
    }
    file << idCounter << '\n';
    for(auto client : clients){
        file << client.getName() << "\n" << client.getAddress() << "\n" << client.getPhone() << "\n";
        shared_ptr<BankAccount>account = client.getAccount();
        account->writeToFile(file);
    }
    file.close();
}

void BankingApplication::displayMenu(){
    cout << "Welcome to FCAI Banking Application\n";
    cout << "1. Create a New Account\n";
    cout << "2. List Clients and Accounts\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Deposit Money\n";
    cout << '\n';
    cout << "Please Enter Choice =========> ";
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
            addClient();
            break;
        case 2:
            listAllClientsAndAccounts();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            depositMoney();
            break;
    }
}

void BankingApplication::addClient(){
    string name, address, phone;
    cin.ignore();
    cout << "Please Enter Client Name =========> ";
    getline(cin, name);
    cout << "Please Enter Client Address =======> ";
    getline(cin, address);
    cout << "Please Enter Client Phone =======> ";
    getline(cin, phone);
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving ??? Type 1 or 2 =========> ";
    int type; cin >> type;
    client c(name, address, phone);

    shared_ptr<BankAccount>account;
    string id = "FCAI-"+to_string(idCounter);
    idCounter++;
    double balance;
    cout << "Please Enter the Starting Balance =========> ";
    cin >> balance;
    if(type == 1){ // basic
        account = make_shared<BankAccount>(id, balance);
        cout << "An Account was created with ID " << id << " and Starting Balance " ;
        cout << balance << " L.E.\n";
    }else{ // saving
        cout << "Please Enter MIN Balance ========> ";
        double minBalance;
        cin >> minBalance;
        account = make_shared<SavingsBankAccount>(id, balance, minBalance);
        cout << "An Account was created with ID " << id << " and Starting Balance ";
        cout << balance << " L.E. and MIN Balance ";
        cout << minBalance << " L.E.\n";
    }
    c.setAccount(account);
    clients.push_back(c);
}

void BankingApplication::withdrawMoney(){
    cout << "Please Enter Account ID =========> ";
    string id;
    cin >> id;
    shared_ptr<BankAccount>account;
    for(auto client : clients){
        if(client.getAccount()->getID() == id){
            account = client.getAccount();
            break;
        }
    }
    account->withdraw();
}

void BankingApplication::depositMoney(){
    cout << "Please Enter Account ID =========> ";
    string id;
    cin >> id;
    shared_ptr<BankAccount>account;
    for(auto client : clients){
        if(client.getAccount()->getID() == id){
            account = client.getAccount();
            break;
        }
    }
    account->deposit();
}

void BankingApplication::listAllClientsAndAccounts(){
    for(auto client : clients){
        for(int i=0; i<15; i++){
            cout << "- ";
        }
        cout << " " << client.getName() << " ";
        for(int i=0; i<15; i++){
            cout << "- ";
        }
        cout << '\n';
        cout << "Address: " << client.getAddress() << '\n';
        cout << "Phone: " << client.getPhone() << '\n';
        client.getAccount()->printInfo(); 
    }
}
