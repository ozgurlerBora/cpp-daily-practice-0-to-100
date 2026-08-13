//
// Created by böo on 13/08/2026.
////
// Created by böo on 11/08/2026.
//
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
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
  std::unordered_map<std::string,std::unique_ptr<Drone>> server;
    server["Player1"]=std::make_unique<Drone>("Bora");
    server["Player2"]=std::make_unique<Drone>("Efe");

    server["Player1"]->fly();


    return 0;

}