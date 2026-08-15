//
// Created by böo on 16/08/2026.
//
#include<iostream>
#include<memory>
#include <unordered_map>
#include<string>
class Ship {
private:
    std::string callsign;
    bool isFriendly;
public:
    Ship(std::string c,bool isf) {
        callsign=c;
        isFriendly=isf;
    }
    bool checkFriendly() {
        return isFriendly;
    }
    std::string getName(){
        return callsign;
    }
    void dock() {
        std::cout<<callsign<<" has successfully docked in the hangar"<<std::endl;
    }
};
int main() {
    std::unordered_map<std::string,std::unique_ptr<Ship>>hangar;
    std::unique_ptr<Ship> incoming1 =std::make_unique<Ship>("Apollo",true);
    std::unique_ptr<Ship> incoming2=std::make_unique<Ship>("BlackBeard",false);

    if (incoming1->checkFriendly()) {
        hangar["Apollo"]=std::move(incoming1);
    }
    else {
        std::cout<<incoming1->getName()<<"is hostile Weapons locked!"<<std::endl;
    }

    if (incoming2->checkFriendly()) {
        hangar["BlackBeard"]=std::move(incoming2);
    }
    else {
        std::cout<<incoming2->getName()<<"is hostile Weapons locked!"<<std::endl;
    }
    hangar["Apollo"]->dock();
    return 0;
}