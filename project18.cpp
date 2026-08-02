//
// Created by böo on 01/08/2026.
//
#include <iostream>
#include <vector>
#include <string>
class Student{
private:
    std::string name;
    double gpa;
public:
    Student(std::string name1,double startgpa) {
        name=name1;
        gpa=startgpa;
    }
    std::string getName() {
        return name;
    }
    void updateGPA(double newGPA) {
        if (newGPA<=4 &&newGPA>=0) {
            gpa=newGPA;
        }
        else {
            std::cout<<"Wrong INPUT"<<std::endl;
        }

    }
    void printTranscript() {
        std::cout<<name<<gpa;
    }
};
class Department {
private:
    std::string deptName;
    std::vector <Student*> enrolled;
public:
    Department(std::string name) {
    deptName=name;
    }
    void enrollStudent(std::string stdname,double strtGPA) {
        Student* temp=new Student(stdname,strtGPA);
        enrolled.push_back(temp);
    }
    Student* findstudent(std::string searchName) {
        for (int i=0;i<enrolled.size();i++) {
            if (searchName==enrolled[i]->getName()) {
                return enrolled[i];
            }
        }
        return nullptr;
    }
    ~Department() {
        for (int i=0 ;i<enrolled.size();i++) {
            delete enrolled[i];
            std::cout<<"Destructor successfully cleared the memory";
        }
    }



};
int main() {
    Department dep1("Math Engineering");
    dep1.enrollStudent("Bora",3.7);
    dep1.enrollStudent("Efe",2.1);
    Student* ptr1=dep1.findstudent("Bora");
    if (ptr1!=nullptr) {
        ptr1->updateGPA(4);
        ptr1->printTranscript();
    }
return 0;











}

