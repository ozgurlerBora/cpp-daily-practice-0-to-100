//
// Created by böo on 05/08/2026.
//
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
class Character {
protected:
    std::string charName;
    int powerLevel;
public:
    Character(std::string name,int level) {
        charName=name;
        powerLevel=level;
    }
    std::string getName() {
        return charName;
    }
    int getLevel() {
        return powerLevel;
    }
};
class Hero : public Character {
private:
    std::string SpecialMove;
public:
    Hero(std::string heroName,int heroPower,std::string move) :Character(heroName,heroPower) {
        SpecialMove=move;
    }
    void useUltimate() {
        std::cout<<""<<charName<<""<<powerLevel<<""<<SpecialMove<<std::endl;
    }
};
class AnimeUniverse {
private:
    std::string universeName;
    std::vector <Hero*> squad;
public:
    AnimeUniverse(std::string name) {
        universeName=name;
    }
    void summonHero(std::string name,int power,std::string move) {
        Hero* temp1=new Hero(name,power,move);
        squad.push_back((temp1));
    }
    Hero* findHero(std::string targetName) {
        for (int i=0;i<squad.size();i++) {
            if (targetName==squad[i]->getName()) {
                return squad[i];
            }
        }
        return nullptr;
    }
    ~AnimeUniverse() {
        for (int i=0;i<squad.size();i++) {
            delete squad[i];
            std::cout<<"memory successfully cleaned"<<std::endl;
        }
    }

};
int main() {
    AnimeUniverse test1("Bleach");
    test1.summonHero("Ichigo",95555,"Getsuga Tenshou");
    test1.summonHero("Byakuya",5555,"Senbonzakura Kageyoshi");
    Hero* ptr1=test1.findHero("Ichigo");
    if (ptr1!=nullptr) {
        ptr1->useUltimate();
    }
    return 0;
}