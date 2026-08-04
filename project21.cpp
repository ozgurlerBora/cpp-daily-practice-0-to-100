//
// Created by böo on 05/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Student {
protected:
    std::string studentName;
    int studentID;
public:
    Student(std::string name,int number) {
        studentName=name;
        studentID=number;
    }
    std::string getName() {
        return studentName;
    }
    int getID() {
        return studentID;
    }
};
class ErasmusStudent : public Student {
private:
    std::string destinationCountry;
public:
    ErasmusStudent(std::string studentName,int studentID,std::string destCountry):Student(studentName,studentID) {
        destinationCountry=destCountry;
    }
    void showDetails() {
        std::cout<<" "<<studentName<<""<<studentID<<""<<destinationCountry<<std::endl;
    }
};
class ExchangeProgram {
private:
    std::string name;
    std::vector<ErasmusStudent*> roster;
public:
    ExchangeProgram(std::string progName) {
        name=progName;
    }
    void acceptStudent(std::string newName,int newID,std::string destCountry) {
        ErasmusStudent* temp=new ErasmusStudent(newName,newID,destCountry);
        roster.push_back(temp);
    }
    ErasmusStudent* searchStudent(int targetID) {
        for (int i=0; i<roster.size();i++) {
            if (targetID==roster[i]->getID()) {
                return roster[i];
            }

        }
        return nullptr;

    }
    ~ExchangeProgram() {
        for (int i=0;i<roster.size();i++) {
            delete roster[i];
            std::cout<<"Memory successfully cleaned"<<std::endl;
        }
    }
};
int main() {
    ExchangeProgram test1("Erasmus");
    test1.acceptStudent("Bora",144,"Portugal");
    test1.acceptStudent(("Efe"),80,"Holland");
    ErasmusStudent* ptr1=test1.searchStudent(144);
    if (ptr1!=nullptr) {
        ptr1->showDetails();
    }
    return 0;






}