//
// Created by böo on 21/08/2026.
//
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <unordered_map>
int main() {
    std::ofstream writer("roster.txt",std::ios::app);
    if (!writer.is_open()) {
        std::cout <<" Error! : Could not open  file for writing!!"<<std::endl;
    }
    std::string n;
    int t;
    bool test;
    std::cout<<"Please enter the name, lift weight , and bool type"<<std::endl;
    std::cin >> n >> t >> test;
    writer << n << " " << t << " " << test << std::endl;
}