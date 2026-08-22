//
// Created by böo on 23/08/2026.
//
#include <iostream>
#include <string>
#include <memory>

class Sensor {
private:
    double* data;
public:
    Sensor() {
        data = new double (899.9);
        std::cout <<" Sensor Online : Ram  Claimed"<<std::endl;
    }
    ~Sensor() {
        delete data;
        std::cout<<"Sensor Offline Ram Freed"<<std::endl;
    }
    Sensor (const Sensor& source) {
        this->data=new double;
        *(this->data)=*(source.data);
    }
    Sensor& operator=(const Sensor& source) {
        if (this==&source) {
            return *this;
        }
        *(this->data)=*(source.data);
        return *this;
    }
};
int main() {
    std::cout<<"Booting up!"<<std::endl;
    {
        Sensor a;
        Sensor b=a;
        Sensor c;
        c=a;
    }
    std::cout <<"Program finishing"<<std::endl;
    return 0;
}

