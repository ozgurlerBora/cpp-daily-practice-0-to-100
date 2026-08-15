//
// Created by böo on 16/08/2026.
//
#include<iostream>
#include<memory>
#include <unordered_map>
#include<string>
class Weapon {
private:
    std::string name;
    int damage;
public:
    Weapon(std::string n,int d) {
        name=n;
        damage=d;
    }
    int getDamage() {
        return damage;
    }
    void equip() {
        std::cout<<name<<" equipped. Damage output: "<<damage<<std::endl;
    }
};
int main() {
    std::unordered_map<std::string,std::unique_ptr<Weapon>> inventory;
    std::unique_ptr<Weapon> droppedLoot =std::make_unique<Weapon>("Iron Sword",15);
    std::unique_ptr<Weapon> cursedDagger=std::make_unique<Weapon>("Rusty Dagger",3);
    if (droppedLoot->getDamage()>10) {
        inventory["Iron Sword"]=std::move(droppedLoot);

    }
    else {
        std::cout<<"Loot is too weak. Left on the ground"<<std::endl;
    }
    if (cursedDagger->getDamage()>10) {
        inventory["Rusty Dagger"]=std::move(cursedDagger);

    }
    else {
        std::cout<<"Loot is too weak. Left on the ground"<<std::endl;
    }
 inventory["Iron Sword"]->equip();
    return 0;


}
