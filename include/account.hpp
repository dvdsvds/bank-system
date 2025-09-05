#pragma once

#include <iostream>
#include <string>
#include <random>

// Account -> bank name, owner, number, balance
class Account {
    public:
        struct OwnerInfo {
            std::string name;
            std::string phone;
            std::string address;
            std::string secret_num;
        };
        const OwnerInfo& getOwnerInfo() const;

    private:
        std::string bankName;
        std::string accountNumber; // 1234-1234-1234
        double balance;

        OwnerInfo ownerinfo;

    public:
        Account(const std::string& bn, const OwnerInfo& oi, const std::string& an, double b);

        std::string getBankName() const;
        std::string getAccountNumber() const;
        double getBalance() const;
        bool getIsAvailable() const;

        void setBankName(const std::string& bn);

        void setOwnerName(const std::string& newName);
        void setOwnerPhone(const std::string& newPhone);
        void setOwnerAddress(const std::string& newAddress);
        void setOwnerSecretNum(const std::string& newSecretNum);

        void deposit(double amount);
        bool withdraw(double amount);

        void print() const;
        static std::string createAccountNumber();
};