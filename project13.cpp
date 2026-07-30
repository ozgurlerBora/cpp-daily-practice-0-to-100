//
// Created by böo on 30/07/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Member {
private:
    std::string MemberName;
    double maxBench;
public:
    Member(std::string name,double bench) {
        MemberName=name;
        maxBench=bench;
    }
    std::string getName() {
        return MemberName;
    }
    void updateBench(double newBench) {
        if (newBench<0) {
            std::cout<<"Invalid Input"<<std::endl;
        }
        if (maxBench<newBench) {
            maxBench=newBench;

        }
        else std::cout<<"Failed to make a new PR better luck next time!"<<std::endl;
    }
    void printRecord() {
        std::cout<<MemberName<<" has "<<maxBench<<" as his bench PR"<<std::endl;
    }

};
class Gym {
private:
    std::string gymName;
    std::vector <Member> roster;
public:
    Gym(std::string newGymName) {
         gymName=newGymName;
    }
    void addMember(std::string newMember,double startingBench) {
        Member tempMember(newMember,startingBench);
        roster.push_back(tempMember);
    }
    void showLeaderboard() {
        for (int i=0;i<roster.size();i++) {
            roster[i].printRecord();
        }
    }
    Member* getMember(std::string searchName) {
        for (int i =0; i<roster.size();i++){
        if (roster[i].getName()==searchName) {
            return &roster[i];
        }
        }
        return nullptr;

    }




};
int main() {
    Gym gym1("Gold Gym");
    gym1.addMember("Bora",120);
    gym1.addMember("Efe",100);
    Member* lifterPtr=gym1.getMember("Bora");
    if (lifterPtr!=nullptr) {
        lifterPtr->updateBench(140);
    }
    gym1.showLeaderboard();
}