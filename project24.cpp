//
// Created by böo on 10/08/2026.
//
#include <iostream>
#include <vector>
#include <string>
class Account {
protected:
    std::string name;
    double number;
public:
    Account(std::string ownerName,double balance) {
        name=ownerName;
        number=balance;
    }
    std::string getName() {
        return name;
    }
    double getBalance() {
        return  number;
    }
};
class CryptoAccount : public Account {
private:
    std::string walletAdress;
public:
    CryptoAccount(std::string ownerName,double balance,std::string address) : Account(ownerName,balance) {
        walletAdress=address;
    }
    void deposit (double Amount) {
        if (Amount<0) {
            std::cout<< "Error can not deposit negative number in to account!"<<std::endl;
        }
        else if (Amount>=0) {
            number=number+Amount;
        }
    }
    void showLedger() {
        std::cout<<name<<""<<number<<""<<walletAdress<<std::endl;
    }
};
class CryptoExchange {
private:
    std::vector<CryptoAccount*> accs ;
    std::string exchangeName;
public:
    CryptoExchange(std::string ename) {
        exchangeName=ename;
    }
    void openAccount(std::string owner,double balance,std::string WalletAddres) {
        CryptoAccount* temp1=new CryptoAccount (owner,balance,WalletAddres);
        accs.push_back(temp1);

    }
    CryptoAccount* findAcc(std::string targetOwner) {
        for (int i=0;i<accs.size();i++) {
            if (targetOwner==accs[i]->getName()) {
                return accs[i];
            }
        }
        return nullptr;
    }
    ~CryptoExchange() {
        for (int i=0;i<accs.size();i++) {
            delete accs[i];
        }
    }
};
int main() {

   CryptoExchange test1 ("Bitcon");
   test1.openAccount("Bora",250000,"ADEFBGF");
   CryptoAccount* ptr1 = test1.findAcc("Bora");
    if (ptr1!=nullptr) {
        ptr1->deposit(500);
        ptr1->showLedger();

    }
        return 0;







    }


