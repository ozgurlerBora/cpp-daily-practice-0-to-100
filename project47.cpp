//
// Created by böo on 12/09/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include  <cmath>
#include <stdexcept>
class Vector {
private:
    std::vector <double> list;
public:
    Vector(std::vector<double> v1) {
        list=v1;
    }
    double getMagnitude() {
        double length=0;
        for (int i=0;i<list.size();i++) {
            length+=pow(list[i],2);

        }
        return sqrt(length);

    }



    double dotProduct(const Vector& other) {
        double result=0;
        if (this->list.size()!=other.list.size()) {
            throw(std::logic_error("Tho vector size are not exact same"));
        }
        for (int i=0;i<this->list.size();i++) {
           result+= this->list[i]*other.list[i];
        }
        return result;
    }
};



int main() {
    Vector A({3.0,4.0});
    Vector B({6.0,8.0});
    double magn=A.getMagnitude();
    std::cout<<magn<<std::endl;
    double product=B.dotProduct(A);
    std::cout<<product<<std::endl;
    return 0;





}