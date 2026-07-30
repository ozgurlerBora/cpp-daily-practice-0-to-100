//
// Created by böo on 26/07/2026.
//
#include <iostream>
#include <string>
#include <vector>
struct Athlete {
    std::string name;
    double vjump;

};
int main() {

    std::vector <Athlete> athletes;
    std::cout <<"Please enter data for 3 different athletes (Name,Vertical Jump) "<<std::endl;
    for (int i = 0 ; i<3;i++) {
       Athlete temp;
        std::cin >> temp.name;
        std::cin >> temp.vjump;
        athletes.push_back(temp);
    }
    int biggest = 0 ;
    std::string bouncy;

    for (int i= 0;i<3;i++) {
        if (athletes[i].vjump>=biggest) {
            biggest=athletes[i].vjump;
            bouncy=athletes[i].name;
        }
    }
    std::cout<<"The biggesst vertical jump is "<<biggest<<"and it belongs to "<<bouncy<<std::endl;
std::cin.ignore(100,'\n');
std::cin.get();

}
