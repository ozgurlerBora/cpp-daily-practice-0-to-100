#include <iostream>

int main() {
  double var1, var2;
  char   var3;
  do {
    std :: cout <<"Enter your desired operator [+]/[-]/[*]/[/] "<< std::endl;
    std::cout <<"If you would like to quit the calculator press Q "<< std::endl;
    std::cin >> var3;
    if (var3=='q' || var3 =='Q') {
        std ::cout <<"Exiting the calc goodbye!" << std::endl;
        break;

    }
    if (var3=='+'||var3=='-'||var3=='/'||var3=='*') {
        std :: cout << "Enter  two numbers please ";
        std::cin >>  var1 >> var2 ;
        std :: cout << " Here is your selected numbers  " << var1 <<  " " << var2 << std::endl;
        switch (var3) {
            case '+':
                std::cout<<"The sum of two numbers is " << var1+var2 << std::endl;
                break;
            case '-':
                std::cout<<"The  difference between two numbers is " << var1-var2 << std::endl;
                break;
            case '*':
                std::cout<<"The two numbers multiplied is " << var1*var2 << std::endl;
                break;
            case '/':
                if (var2!=0) {
                    std::cout<<"The first number divided by second is "<< var1/var2 << std::endl;
                }
                else std ::cout <<"ERROR : You cant divide by zero!" << std::endl;
                break;
            default:
                std::cout<<"Something went wrong please try again!"<<  std::endl;
                break;
        }
    }
    else std :: cout << "Invalid Operator please try again " << std::endl;



   } while (var3!='Q' && var3!='q');

    return 0;
}
