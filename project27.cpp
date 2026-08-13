//
// Created by böo on 11/08/2026.
//
#include <iostream>
#include <unordered_map>
#include <string>
void checkAthlete (std::unordered_map<std::string,int>& database ,std::string targetName) {
    if (database.find(targetName)!=database.end()) {
        std::cout<<"The count for the "<<targetName<<"is" << database[targetName]<<std::endl;
    }
    else {
        std::cout<<"ERROR! Athlete not found in the database"<<std::endl;
    }
}
int main() {
    std:: unordered_map<std::string,int > Count;
    Count["Bora"]=55;
    Count["Efe"]=8;
    Count["Igor"]=3;
    Count["Bora"]++;
checkAthlete(Count,"Bora");
checkAthlete(Count,"Alex");






}


