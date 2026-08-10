//
// Created by böo on 11/08/2026.
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>
class Drone {
private:
    std::string model;
public:
    Drone(std::string name) {
        model=name;
    }
    void fly() {
        std::cout<<model<<" is flying"<<std::endl;
    }
    ~Drone() {
        std::cout<<model<<" meemory has been cleared automatically!"<<std::endl;
    }




};
int main () {
    std::unique_ptr<Drone> ptr= std::make_unique<Drone>("Reaper");
    ptr->fly();
    std::vector <std::unique_ptr<Drone>> vec1;
    std::unique_ptr<Drone> ptr2 = std::make_unique<Drone>("Predator");
    std::unique_ptr<Drone> ptr3 = std::make_unique<Drone>("GlobalHawk");
    vec1.push_back(std::move(ptr2));
    vec1.push_back(std::move(ptr3));
    for (int i=0;i<vec1.size();i++) {
        vec1[i]->fly();
    }


    return 0;

}