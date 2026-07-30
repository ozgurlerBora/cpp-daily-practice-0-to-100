//
// Created by böo on 27/07/2026.
//
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

class liftracker {
private:
    std::string exname;
    double prweight;
public:
    liftracker(std::string newexname , double neweight) {
        if (neweight<0) {
            std::cout<<"Invalid Weight!";
            neweight=0;
        }
        exname=newexname;
        prweight=neweight;

    }
void attemptLift (double weightLifted) {
         if (weightLifted<=0 ) {
             std::cout << "Invalid weight";
         }
        else if (weightLifted>prweight) {
            prweight=weightLifted;
            std::cout<<"New Pr SET! New PR is : "<<prweight<<std::endl;

        }
        else if (weightLifted<prweight) {
            std::cout<<"You have failed the PR but better luck next time!"<<std::endl;
        }
        else std::cout<<"You lifted exactly the same as the last time!"<<std::endl;
    }
void displayStats () {
        std::cout<<"For the exercise : "<<exname<<" current PR is "<<prweight<<std::endl;
    }

};

class GymSession {
private:
    std::string splitName;
    std::vector <liftracker> exercises;
public:
    GymSession(std::string name) {
        splitName=name;
    }
    void addExercise(std::string name,double startingweight) {
        liftracker tempTracker (name,startingweight);
        exercises.push_back(tempTracker);
    }
    void showallPR() {
        for (int i=0;i<exercises.size();i++) {
            exercises[i].displayStats();
        }
    }
};

int main() {
    GymSession pushday ("Push Day");
    pushday.addExercise("Bench Press",120);
    pushday.addExercise("Overhead Press",80);
    pushday.showallPR();
    std::cin.ignore(100,'\n');
    std::cin.get();

}
