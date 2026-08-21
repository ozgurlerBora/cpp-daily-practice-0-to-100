//
// Created by böo on 22/08/2026.
//
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <fstream>
#include <algorithm>
class Lifter {
private:
    std::string name;
    int weight;
public:
    Lifter(std::string n,int w) {
        name=n;
        weight=w;
    }
    int getW() {
        return  weight;
    }
    std::string getName() {
        return name;
    }
    bool operator>(Lifter& opponent) {
        return this->weight>opponent.weight;
    }

};
int main() {
    std::vector <Lifter> competition;
    competition.push_back( Lifter("Bora",1200));
    competition.push_back(Lifter("Alex",1600));
    competition.push_back(Lifter("Igor",900));
    competition.push_back(Lifter(("MMarcus"),1800));
    std::sort(competition.begin(),competition.end(),[](Lifter& a,Lifter& b) {
        return a.getW()>b.getW();
    });
   std::cout <<"!!!!!! OFFICAL LEADERBOARD !!!!! "<<std::endl;
    for (int i =0;i<competition.size();i++) {
        std::cout << i+1<<"."<<competition[i].getName()<<" - "<<competition[i].getW()<<std::endl;
    }
    return 0;
}