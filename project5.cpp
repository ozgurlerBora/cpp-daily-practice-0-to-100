//
// Created by böo on 24/07/2026.
/// RACECAR
#include <iostream>
#include <string>
int main() {
    std::string word;
    bool isPalindrome = true;
    std::cout << "Type a word to check if its palindrome"<<std::endl;
    std::cin >> word;
    for (int i = 0; i<word.length()/2;i++) {
        if (word[i]!=word[word.length()-i-1]) {
            isPalindrome=false;
            break;
        }
    }
    if (isPalindrome==false) {
        std::cout <<"The word you've entered is not palindrome"<<std::endl;

    }
    else if (isPalindrome==true) {
        std::cout << "The word you've entered is palindrome "<<std::endl;
    }
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0 ;
}