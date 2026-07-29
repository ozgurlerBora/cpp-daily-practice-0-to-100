#include <iostream>

bool isPrime (int a ) {
   bool temp = true;
   for (int i = 2; i<a-1; i++) {
      if (a%i== 0) {
         temp=false;
         return temp;

      }


   }
   return temp;

}
int main () {
   int x = 0 ;
   std::cout << "Enter a maximum number for a program to write every prime number between 2 and that number." << std::endl;
   std::cin >> x;
   for (int i =2; i<x; i++) {
      if (isPrime(i)) {
         std::cout<<i<<::std::endl;

      }
      else continue;

   }
   std::cin.ignore(100,'\n');
   std::cin.get();
}