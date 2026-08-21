//
// Created by böo on 22/08/2026.
//
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <fstream>
#include <algorithm>
class Student {
private:
    std::string name;
    double score;
    int minutestaken;
public:
    Student(std::string n,double s,int m) {
        name=n;
        score=s;
        minutestaken=m;
    }
    std::string getName() {
        return name;
    }
    double getScore() {
        return score;

    }
    int getTime() {
        return minutestaken;
    }
};
int main() {
    std::vector <Student> classRoster;
    classRoster.push_back(Student ("Alex",95,45));
    classRoster.push_back(Student ("Bora",95,30));
    classRoster.push_back(Student ("Can",80,50));
    classRoster.push_back(Student ("Deniz",80,40));
    std::sort (classRoster.begin(),classRoster.end(),[](Student & a, Student & b) {
        if (a.getScore()==b.getScore()) {
            return a.getTime()<b.getTime();
        }
        return a.getScore()>b.getScore();
    });
    std::cout<<"!!!!!!! Class LEADERBOARD !!!!!!!! "<<std::endl;
    for (int  i=0;i<classRoster.size();i++) {
        std::cout<<i+1<<"."<<classRoster[i].getName()<<" with a score of "<< classRoster[i].getScore()<<" with a time of "<<classRoster[i].getTime()<<std::endl;
    }
    return 0;



}