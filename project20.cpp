//
// Created by böo on 04/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
class Employee {
protected:
    std::string name;
    double salary;
public:
    Employee(std::string newname,double newsalary) {
        name=newname;
        salary=newsalary;
    }
    void showDetails() {
        std::cout<<name<<" has "<< salary<<" as his salary."<<std::endl;
    }


};
class SoftwareEngineer : public Employee {
private:
    std::string programmingLang;
public:
    SoftwareEngineer(std::string engName,double engSalary,std::string engprogrammingLang):Employee(engName,engSalary) {
        programmingLang=engprogrammingLang;
    }
    void writeCode() {
        std::cout<<name<<" is writing code in "<<programmingLang<<std::endl;
    }

};
int main() {
    Employee emp1 ("Mert",50000);
    emp1.showDetails();
    SoftwareEngineer eng1 ("Bora",80000,"C++");
    eng1.showDetails();
    eng1.writeCode();
}
