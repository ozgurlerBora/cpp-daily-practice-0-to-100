//
// Created by böo on 20/08/2026.
//
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <unordered_map>
class Lifter {
private:
    std::string name;
    int total;
    bool isTested;
public:
    Lifter(std::string n,int t,bool c) {
        name=n;
        total=t;
        isTested=c;
    }
    void lift() {
        std::cout <<name<<" steps on the platfrom with a total of  "<<total<<std::endl;
    }


};
int main() {
    std::unordered_map<std::string,std::unique_ptr<Lifter>> database;
    std::ifstream scanner("roster.txt");
    if (!scanner.is_open()) {
        std::cout <<"Couldnt read the file "<<std::endl;
        return 1;
    }
    std::string tempName;
    int tempTotal;
    bool tempTest;
    while (scanner>>tempName>>tempTotal>>tempTest) {
        database[tempName]=std::make_unique<Lifter>(tempName,tempTotal,tempTest);
    }
    for (auto const & pair : database) {
        pair.second->lift();
    }
    scanner.close();
    return 0;




}