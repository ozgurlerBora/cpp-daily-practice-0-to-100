//
// Created by böo on 24/07/2026.
//
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
int main() {
    std::vector<double> myVector;
    std::vector <double> vectorB;
    double sum = 0 ;
    double sum2 = 0 ;
    double tempInput = 0 ;
    double final = 0 ;
    std :: cout << "Please input  the X, Y, Z  coordinates for the first vector one by one " << std::endl;
    for (int i=0;i<3;i++) {
        std::cin >> tempInput;
        myVector.push_back(tempInput);
    }
    std::cout <<" Please input the X, Y, Z coordinates for the second vector one by one "<< std::endl;
    for (int i = 0; i<3; i++ ) {
        std::cin >> tempInput;
        vectorB.push_back(tempInput);
    }
    for (int i=0; i<vectorB.size();i++) {
        sum2=(myVector[i]*vectorB[i])+sum2;

    }
    for (int i = 0; i<myVector.size();i++) {
        sum= sum+ pow(myVector[i],2);

    }
    final= sqrt((sum));

    std::cout << "The norm of the vector you've provided is "<<final<< std::endl;
    std::cout <<"And The dot product of  the 2 vector  you've provided is "<< sum2<<std::endl;
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0 ;
}