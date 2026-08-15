//
// Created by böo on 16/08/2026.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
class Account {
private:
    std::string owner;
    double balance;
public:
    Account(std::string n,double b) {
        owner=n;
        balance=b;
    }
    double getBalance() {
        return balance;
    }
    void withdraw(double amount) {
        if (balance>=amount) {
            balance=balance-amount;
            std::cout<<owner<<" withdrew "<<amount<<"New balance : $ "<< balance<<std::endl;
        }
        else std::cout<<"Transaction denied for "<<owner<<" Insufficent balance"<<std::endl;
    }
};
void atmWithdrawal(std::unordered_map<std::string,std::unique_ptr<Account>>&bank,std::string targetName,double amount) {
    if (bank.find(targetName)!=bank.end()) {
        bank[targetName]->withdraw(amount);
    }
    else {
        std::cout<<"Error: Account"<<targetName<<" does not exist!"<<std::endl;
    }
}
int main() {
    std::unordered_map<std::string,std::unique_ptr<Account>> acc1;
    acc1["Bora"]=std::make_unique<Account>("Bora",500);
    acc1["Efe"]=std::make_unique<Account>("Efe",50);
    atmWithdrawal(acc1,"Bora",400);
    atmWithdrawal(acc1,"Efe",100);
    atmWithdrawal(acc1,"Igor",100);
    return 0;



}