//
// Created by böo on 19/08/2026.
//
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
class Lifter {
private:
    std::string name;
    int total;
    bool isTested;
public:
    Lifter(std::string n,int t,bool isT) {
        name=n;
        total=t;
        isTested=isT;
    }
    std::string getName() {
        return name;
    }
    int getTotal(){
        return total;
    }
    bool getTest() {
        return isTested;
    }
    void lift() {
        std::cout<<name<<" is on the platform with a "<<total<<"total!"<<std::endl;
    }
};
void callToPlatform(std::unordered_map<std::string,std::unique_ptr<Lifter>>&roster,std::string targetName) {
    if (roster.find(targetName)!=roster.end()) {
        roster[targetName]->lift();
    }
    else {
        std::cout<<"Error!: "<< targetName<<"is not on the active roster!"<<std::endl;
    }




}
int main() {
    std::unordered_map<std::string,std::unique_ptr<Lifter>> roster;
    std::vector<std::unique_ptr<Lifter>> waitingRoom;
    waitingRoom.push_back(std::make_unique<Lifter>("Bora",1200,true));
    waitingRoom.push_back(std::make_unique<Lifter>("Alex",1600,false));
    waitingRoom.push_back(std::make_unique<Lifter>("Igor",900,true));
    for (int i = 0; i<waitingRoom.size();i++) {

        if (waitingRoom[i]->getTotal()>=1000 && waitingRoom[i]->getTest()==true) {
            roster[waitingRoom[i]->getName()]=std::move(waitingRoom[i]);
        }
        else {
            std::cout<<waitingRoom[i]->getName()<<" disqualified."<<std::endl;
        }
    }
    callToPlatform(roster,"Bora");
    callToPlatform(roster,"Alex");

 return 0;

}
