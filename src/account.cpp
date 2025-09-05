#include "account.hpp"

Account::Account(const std::string& bn, const Account::OwnerInfo& oi, const std::string& an, double b)
: bankName(bn), ownerinfo(oi), accountNumber(an), balance(b) {};

void Account::setOwnerName(const std::string& newName) {
    this->ownerinfo.name = newName;
}

void Account::setOwnerPhone(const std::string& newPhone) {
    this->ownerinfo.phone = newPhone;
}

void Account::setOwnerAddress(const std::string& newAddress) {
    this->ownerinfo.address = newAddress;
}

void Account::setOwnerSecretNum(const std::string& newSecretNum) {
    this->ownerinfo.secret_num = newSecretNum;
}

const Account::OwnerInfo& Account::getOwnerInfo() const {
    return ownerinfo;
}

std::string Account::getBankName() const {
    return bankName;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBankName(const std::string& bn) {
    bankName = bn;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if(amount > balance) {
        std::cout << "Your balance is not enough" << std::endl;
        return false;
    } 

    balance -= amount;
    std::cout << amount << "won was withdrawn" << std::endl;
    std::cout << "Balance:" << balance << std::endl;
    return true;
}

void Account::print() const {
    std::cout << "Bank:" << bankName <<  std::endl
              << "Owner:" << ownerinfo.name << " "
                          << ownerinfo.phone << " "
                          << ownerinfo.address << " "
                          << ownerinfo.secret_num  << std::endl
              << "Account Number:" << accountNumber << std::endl 
              << "Balance:" << balance << std::endl;
}


std::string Account::createAccountNumber() {
    std::string an;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(0, 9);

    for(int i = 0; i < 12; i++) {
        an += std::to_string(dis(gen));
    }

    an.insert(4, "-");
    an.insert(9, "-");

    return an;
}
