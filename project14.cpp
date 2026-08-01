//
// Created by böo on 30/07/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Adventurer {
private:
    std::string advName;
    char rank;
    int questsCompleted;

public:
    Adventurer(std::string newadvName) {
        advName=newadvName;
        rank='C';
        questsCompleted=0;
    }
    std::string getName() {
        return advName;
    }
    void completeQuest() {
        questsCompleted++;
        if (questsCompleted==5) {
            std::cout<<"Congratulations you've upgraded your rank to B!"<<std::endl;
            rank='B';
        }
        else if (questsCompleted==10) {
            std::cout<<"Congratulations you've upgraded your rank to A!"<<std::endl;
            rank='A';
        }

    }
    void printStatus() {
        std::cout<<"Currently "<<advName<<" is on rank "<<rank<<" and completed exactly "<<questsCompleted<<" Quests."<<std::endl;
    }

};
class Guild {

private:
    std::string guildName;
    std::vector<Adventurer> guild;
public:
    Guild(std::string newGuildName) {
        guildName=newGuildName;
    }
    void addAdventurer(std::string newAdvname) {
        Adventurer temp(newAdvname);
        guild.push_back(temp);

    }
    void displayGuild() {
        for (int i=0;i<guild.size();i++) {
            guild[i].printStatus();
        }
    }
    Adventurer* getAdventurer(std::string searchName) {
        for (int i=0;i<guild.size();i++) {
            if (guild[i].getName()==searchName) {
                return &guild[i];
            }
        }
        return nullptr;
    }

};
int main() {
    Guild newGuild("Xunevia");
    newGuild.addAdventurer("Bora");
    newGuild.addAdventurer("Mert");
    newGuild.addAdventurer("Efe");
    Adventurer* ptr1=newGuild.getAdventurer("Bora");
    if (ptr1!=nullptr) {
        for (int i=0;i<6;i++) {
            ptr1->completeQuest();
        }
    }
    newGuild.displayGuild();
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0;




}