cmake_minimum_required(VERSION 3.22)
project(Banking_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Banking_System
        BankAccount.cpp
        BankAccount.h
        BankingApplication.cpp
        BankingApplication.h
        client.cpp
        client.h
        main.cpp
        SavingsBankAccount.cpp
        SavingsBankAccount.h)
