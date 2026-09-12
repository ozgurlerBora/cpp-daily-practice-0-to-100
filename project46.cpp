//
// Created by böo on 12/09/2026.
//
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>


class Analyzer {
private:
    std::vector <double> numb;
    std::string name;
public:
    Analyzer(std::string n) {
        name=n;
    }
    void addNumber (double val) {
        numb.push_back(val);
    }
    void getMean() {
        double avg=0;
        if (numb.size()==0) {
            throw(std::logic_error("Vector is empty!!"));
        }
        for (int i=0;i<numb.size();i++){
        avg+=numb[i];
        }
        std::cout<< avg/numb.size()<<std::endl;
    }
    void getMax() {
        double max=numb[0];
        if (numb.size()==0) {
            throw(std::logic_error("Vector is empty!!"));
        }
        for (int i=0;i<numb.size();i++) {
            if (numb[i]>max) {
                max=numb[i];
            }

        }
        std::cout<< max <<std::endl;
    }
    void display() {
        for (int i=0;i<numb.size();i++) {
            std::cout<<numb[i]<<"  ";
        }
    }

};
int main() {
    Analyzer a1 ("veri1");
  //   a1.getMax();  // Safety works;.
    a1.addNumber(15.5);
    a1.addNumber(42.0);
    a1.addNumber(8.2);
    a1.addNumber(100.1);
    a1.getMean();
    a1.getMax();
    a1.display();

    return 0;
}