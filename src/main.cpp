#include "account.hpp"

int main() {
    std::vector<std::string> bank = {"A", "B", "C"};
    std::vector<Account> accountList;

    int choice;
    while(true) {
        std::cout << "1. Create" << std::endl;
        std::cout << "2. Info" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Withdraw" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "> ";

        std::cin >> choice;
        std::cin.ignore();

        if(choice == 1) {
            if(accountList.size() > 5) {
                std::cout << "Can't create new account" << std::endl;
            } else {
                Account::OwnerInfo oi;
                int banknum;
                std::string name, phone, address, secret;

                std::cout << "Choose a bank for opening an account" << std::endl;
                std::cout << "[1]A [2]B [3]C" << std::endl;
                std::cout << "> ";
                std::cin >> banknum;
                std::cin.ignore();

                std::string chosenBank = bank[banknum - 1];

                std::cout << "Name:";
                std::getline(std::cin, oi.name);

                std::cout << "Phone:";
                std::getline(std::cin, oi.phone);

                std::cout << "Address:";
                std::getline(std::cin, oi.address);

                std::cout << "Secret Number:";
                std::getline(std::cin, oi.secret_num);

                std::string accountNumber = Account::createAccountNumber();
                double balance = 0.0;

                Account newAccount(chosenBank, oi, accountNumber, balance);
                accountList.push_back(newAccount);
            }
        } else if(choice == 2) { // show info
            for(const auto& ac : accountList) {
                ac.print();
            }
        } else if(choice == 3) { // deposit
            double amount;
            if(accountList.empty()) {
                std::cout << "There is no available account. Please create account." << std::endl;
            } else {
                
                std::cout << "Amount to deposit:";
                std::cin >> amount;
                std::cin.ignore();
            }
        } else if(choice == 4) { // withdraw

        } else if(choice == 5) { // exit
            break;
        }
    }
}