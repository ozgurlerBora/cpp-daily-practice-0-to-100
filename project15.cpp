//
// Created by böo on 30/07/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Weapon {
private:
    std::string name;
    int damage;
public:
    Weapon(std::string newName,int newDamage) {
        name=newName;
        damage=newDamage;
    }
    void swing() {
        std::cout<<name<<damage<<std::endl;
    }
};
int main() {
    Weapon* sword=new Weapon ("Excalibur",50);
    sword->swing();
    delete sword;
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0;

}