//
// Created by böo on 20/08/2026.
//
#include <iostream>
#include <fstream>
#include <string>
/* int main() {
    std::ifstream fileScanner ("athletes.txt");

    if (!fileScanner.is_open()) {
        std::cout <<" Error : Could not open the file "<< std::endl;
        return 1;
    }
    std::string currentLine;
    while (std::getline(fileScanner,currentLine)) {
        std::cout<<"Read from file: " << currentLine <<std::endl;
    }
fileScanner.close();
    return 0;
} */
int main() {
    std::ifstream fscan ("roster.txt");
    if (!fscan.is_open()) {
        std::cout <<"Error : could not open the filed"<<std::endl;
        return 1;
    }
    std::string currentstring;
    int n;
    bool isT;
    while (fscan>>currentstring>>n>>isT) {
        std::cout << "Lifter "<<currentstring
                  << " Number "<<n
                  << " Tested "<<isT<<std::endl;
    }
    fscan.close();
    return 0;
}