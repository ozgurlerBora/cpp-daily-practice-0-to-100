//
// Created by böo on 23/07/2026.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
int main () {
    srand(time(0));

    int target= rand() %100+1;
    int guess = 0 ;
    int attempt = 0 ;

    std :: cout << "The Target Number is :  " << target << std::endl;

    do {
        std::cout << "Please guess a number" << std::endl;
        std::cin >> guess;
        attempt=attempt+1;
        if (guess>target ) {
            std::cout<<"The number you've guessed is higher than the target number"<< std::endl;

        }
        else if (guess<target) {
            std::cout<<"The number you've guessed is lower than the target number "<<std::endl;

        }
        else break;





    } while (guess!=target);
    std::cout<<"You've correctly guessed the random number"<<std::endl;
    std::cout<<" It took " << attempt << " attempts for you to guess the number! " << std::endl;
    std::cout<<"Press Enter to exit";
    std::cin.ignore();
    std::cin.get();
    return (0);





}