//
// Created by böo on 13/08/2026.
//
#include <memory>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
class Athlete {
private:
    std::string name;
    bool isBanned ;
public:
    Athlete(std::string n,bool b) {
        name=n;
        isBanned=b;
    }
    bool checkBanned() {
        return isBanned;
    }
    void workout() {
        std::cout<<name<<"is hitting the weights"<<std::endl;
    }

};
int main() {
    std::unordered_map <std::string,std::unique_ptr<Athlete>> athleteGym;
    std::unique_ptr<Athlete> ptr1=std::make_unique<Athlete>("Alex",true);
    std::unique_ptr<Athlete> ptr2=std::make_unique<Athlete>("Bora",false);
    if (ptr1->checkBanned()) {
        std::cout<<"Alex is banned. Entry denied"<<std::endl;
    }
    else {
athleteGym["Alex"]=std::move(ptr1);
    }
    if (ptr2->checkBanned()) {
        std::cout<<"Bora is banned. Entry denied"<<std::endl;
    }
    else {
        athleteGym["Bora"]=std::move(ptr2);
    }
athleteGym["Bora"]->workout();
    return 0;







}