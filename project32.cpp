//
// Created by böo on 15/08/2026.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>

class Athlete {
private:
    std::string name;
    int workOutcount;
    bool hasPaid;
public:
    Athlete(std::string n,bool h) {
        name=n;
        hasPaid=h;
        workOutcount=0;

    }
    bool getPaidStatus() {
        return hasPaid;
    }
    void checkIn() {
        workOutcount++;
        std::cout<<"["<<name<<"] has checked in. Total workouts this mont :"<<workOutcount<<std::endl;
    }
};
void scanCard(std::unordered_map<std::string,std::unique_ptr<Athlete>>& database,std::string targetName) {
   if (database.find(targetName)==database.end()) {
       std::cout<<"Error:Athlete has not been found!"<<std::endl;
   }
    else if (database[targetName]->getPaidStatus()){
    database[targetName]->checkIn();
    }
    else {
        std::cout<<"Access denied. Membership Payment required for "<<targetName<<std::endl;

    }

}
int main() {
    std::unordered_map<std::string,std::unique_ptr<Athlete>> gym;
    gym["Bora"]=std::make_unique<Athlete>("Bora",true);
    gym["Efe"]=std::make_unique<Athlete>("Efe",false);
    gym["Igor"]=std::make_unique<Athlete>("Igor",true);
    scanCard(gym, "Bora");
    scanCard(gym,"Bora");
    scanCard(gym,"Efe");
    scanCard(gym,"Alex");
    return 0;
}