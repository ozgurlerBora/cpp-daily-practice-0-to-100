//
// Created by böo on 23/07/2026.
//
#include <iostream>
#include <string>
int main() {
    std::string word;
    int shift  ;
    std:: cout << " Enter a single word to encrypt (no spaces pls :(,)" << std::endl;
    std::cin>> word;
    std :: cout <<"Enter how many times you wanna shift every single letter in the word" << std::endl;
    std::cin>>shift;
    for (int i = 0; i< word.length();i++) {
        if (word[i] >= 'A' && word[i]<='Z') {
            word[i]= (word[i]-'A'+shift)% 26 + 'A';
        }
        else if (word[i]>='a'&& word[i]<='z') {
            word[i]= (word[i]-'a'+shift)%26 +'a';
        }


    }
    std::cout<<"Your new word is : " << word << std::endl;
    std::cin.ignore(100,'\n');
    std::cin.get();
    return 0 ;
}