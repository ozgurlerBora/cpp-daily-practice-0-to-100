//
// Created by böo on 07/09/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Vector {
private:
    int s;
    std::vector <double> v;
public:
    Vector(int size) {
        s=size;
        v=std::vector<double>(size,0.0);
    }
    void setValue(int index,double val) {
        v[index-1]=val;
    }
    void display() {
        for (int i=0;i<v.size();i++) {
            std::cout<< v[i] <<std::endl;
        }

    }
    Vector operator+(const Vector& second) {
        Vector result (this->s);
        if (this->s!=second.s) {
            throw (std::runtime_error("Error cant add two different sized vectors!"));
        }
        else {
            for (int i=0;i<s;i++) {
                result.v[i]=this->v[i]+second.v[i];
            }
            return result;
        }
    }
};