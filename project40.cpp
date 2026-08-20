//
// Created by böo on 21/08/2026.
//
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

class Lifter {
private:
    std::string name;
    int weight;
public:
    Lifter(std::string n,int w) {
        name=n;
        weight=w;
    }
    std::string getName() {
        return name;
    }
    int getW() {
        return weight;
    }
    bool operator>(Lifter& opponent ) {
        return this->weight>opponent.weight;
    }
};
int main() {
    Lifter lifter1 ("Bora",1200);
    Lifter  lifter2 ("Igor",90);
    if (lifter1>lifter2) {
        std::cout <<lifter1.getName()<<"Wins! with a total weight of "<<lifter1.getW()<<std::endl;
    }
    else {
        std::cout  <<lifter2.getName()<<" Wins! with a total weight of "<<lifter2.getW()<<std::endl;

    }
    return 0;
    

}
