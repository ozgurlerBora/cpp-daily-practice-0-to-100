//
// Created by böo on 30/07/2026.
//
#include <iostream>
#include <string>
#include <vector>

void superCharge(int* ptr) {
    if (ptr!=nullptr){
    *ptr=*ptr*5;
    }
}





int main() {
    int powerLevel =10;
    std::cout<<powerLevel<<std::endl;
    superCharge(&powerLevel);
    std::cout<<powerLevel<<std::endl;
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0;
}