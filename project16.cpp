//
// Created by böo on 01/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Player {
private:
    std::string name;
    int totalPoints;
public:
    Player(std::string newName) {
        name=newName;
        totalPoints=0;
    }
    std::string getName() {
        return name;
    }
    void score(int points) {
        if (points<0) {
            std::cout<<"Wrong Input";
            totalPoints=totalPoints;
        }
        else {
            totalPoints=points+totalPoints;
        }
    }

    void printStats() {
        std::cout<<name<<" Has "<<totalPoints<<" points "<<std::endl;
    }

};
class Team {
private:
    std::string teamName;
    std::vector <Player*> roster;
public:
    Team(std::string newTeamName) {
        teamName=newTeamName;
    }
    void signPlayer(std::string name) {
        Player* player1 =new Player (name);
        roster.push_back(player1);

    }
    Player* getPlayer(std::string searchName) {
        for (int i=0;i<roster.size();i++) {
            if (searchName==roster[i]->getName()) {
                return roster[i];
            }
        }
        return nullptr;
    }
    void disband() {
        for (int i=0;i<roster.size();i++) {
            delete roster[i];
        }
    }
};
int main() {
    Team team1 ("Yildizlar");
    team1.signPlayer("Bora");
    team1.signPlayer("Efe");
    Player* getplayer= team1.getPlayer("Bora");
    if (getplayer!=nullptr) {
        getplayer->score(30);
        getplayer->printStats();

    }
    team1.disband();
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0;




}