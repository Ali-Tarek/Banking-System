#include "client.h"

client::client(string name, string address, string number) : Name(name), Address(address), Phone(number) {}

void client::setName(string name) {
    Name = name;
}

void client::setAddress(string address) {
    Address = address;
}

void client::setPhone(string number) {
    Phone = number;
}

string client::getName() {
    return Name;
}

string client::getAddress() {
    return Address;
}

string client::getPhone() {
    return Phone;
}
