//
// Created by böo on 27/07/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Player {
private:
    std::string name;
    int totalPoints = 0;
    int gamesPlayed= 0;
public:
    Player(std::string newname) {
        name=newname;
        totalPoints=0;
        gamesPlayed=0;

    }
    void logGame(int pointsScored) {
        if (pointsScored<0) {
            std::cout<<"Error points scored cannot be lower than 0 "<<std::endl;

        }
        else {
            totalPoints=pointsScored+totalPoints;
            gamesPlayed++;
        }
    }
    void printStats() {
            int ppg = 0;
            if (gamesPlayed==0) {
                ppg=0;

            }
            else {
                ppg=totalPoints/gamesPlayed;
            }
            std::cout<<name<<"Has "<<ppg<<"points per average game "<<std::endl;
        }
    std::string  getName() {
        return name;


    }
    };
class Team {
private:
    std::string teamName;
    std::vector <Player> roster;
public:
    Team(std::string name) {
        teamName=name;
    }
    void signPlayer(std::string PlayerName) {
        Player tempRoster (PlayerName);
        roster.push_back(tempRoster);
    }
    void showBoxScore() {
        for (int i=0;i<roster.size();i++) {
            roster[i].printStats();
        }
    }
    Player* getplayer(std::string TargetName) {
        for(int i=0;i<roster.size();i++) {
            if(roster[i].getName()==TargetName) {
                return &roster[i];
            }
        }
        return nullptr;
    }


};
int main() {
   Team team1 ("Yildizlar");
    team1.signPlayer("Bora");
    Player* starPlayer= team1.getplayer("Bora");
    if(starPlayer!=nullptr) {
        starPlayer->logGame(30);
    }
    team1.showBoxScore();

std::cin.ignore(100,'\n');
std::cin.get();
    return 0;

}
