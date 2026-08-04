//
// Created by böo on 05/08/2026.
//
#include <iostream>
#include <vector>
#include <string>
class Athlete {
protected:
    std::string athname;
    double athWeight;
public:
    Athlete(std::string name,double weight) {
        athname=name;
        athWeight=weight;
    }
    std::string getName() {
        return athname;
    }
    double getWeight(){
        return athWeight;
    }
};
class Bodybuilder : public Athlete {
private:
    double bfPercentage;
public:
    Bodybuilder(std::string name,double weight,double bfp):Athlete(name,weight) {
        bfPercentage=bfp;
    }
    void printMetrics() {
        std::cout<<""<<athname<<""<<athWeight<<""<<bfPercentage<<std::endl;
    }
};
class Gym{
private:
    std::string gymName;
    std::vector <Bodybuilder*> squad;
public:
    Gym(std::string name) {
        gymName=name;
    }
    void registerAthlete(std::string name,double weight,double bfperc) {
        Bodybuilder* temp1=new Bodybuilder(name,weight,bfperc);
        squad.push_back((temp1));
    }
    Bodybuilder* findAthlete(std::string targetName) {
        for (int i =0;i<squad.size();i++) {
            if (targetName==squad[i]->getName()) {
                return squad[i];
            }
        }
        return  nullptr;
    }
    ~Gym() {
        for (int i=0;i<squad.size();i++) {
            delete squad[i];
            std::cout<<"Memory successfully cleaned"<<std::endl;
        }
    }
};
int main() {
    Gym test1("GOLD");
    test1.registerAthlete("Bora",70,11);
    test1.registerAthlete("Efe",110,25);
    Bodybuilder* ptr1=test1.findAthlete("Bora");
    if (ptr1!=nullptr) {
        ptr1->printMetrics();
    }
    return 0;
}