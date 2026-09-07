//
// Created by böo on 08/09/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
class   Acc {
private:
    std::string name;
    double balance;
public:
    Acc(std::string n , double b) {
        if (b<0) {
            throw(std::runtime_error("Can't open an account with negative balance"));
        }
        name=n;
        balance=b;

    }

    void deposit(double amount) {
        if (amount<=0) {
            throw (std::runtime_error("Can't deposit 0 or lower number!"));

        }
        balance+=amount;
    }
    void withdraw ( double amount){
        if (amount>balance|| amount<=0 ) {
            throw (std::runtime_error("Invalid amount to withdraw!"));
        }
        balance-=amount;
    }
    void display() {
        std::cout<<"Account  belongs to : "<< name  <<" current balance is "<< balance<<std::endl;
    }
};
    int main() {
        Acc a1("bora",100);
        a1.deposit(50);
        try {
            a1.deposit(-20);
            a1.withdraw(1000);
            a1.withdraw(30); // Testing if try and catch blocks skip the rest of the codes inside if catches any errors
            // found that it does skips the rest of the code so writing seperate try catch blocks for every function.
        } catch (const std::runtime_error& e) {
            std::cerr<<"Caught Error : "<< e.what()<<std::endl;
        }
        try {
            a1.withdraw(1000);
        }
        catch ( const std::runtime_error& e ) {
            std::cerr<<"Caught Error : " << e.what()<<std::endl;
        }

        a1.withdraw(30);
    a1.display();









    }




