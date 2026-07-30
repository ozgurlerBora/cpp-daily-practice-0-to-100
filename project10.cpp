        //
// Created by böo on 29/07/2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
class Employee {
private:
        std::string name;
        double hourlyRate;
        int hoursWorked;
public:
        Employee(std::string newemployeename,double NhourlyRate,int NhoursWorked) {

                if (hourlyRate<0 || hoursWorked<0) {
                        std::cout<<"Wrong  hourly rate or hours worked so both numbers automatically set to 0 "<<std::endl;
                        hourlyRate=0;
                        hoursWorked=0;
                }
                name=newemployeename;
                hourlyRate=NhourlyRate;
                hoursWorked=NhoursWorked;


        }
        void printPaycheck() {
                double sum=0;
                if (hoursWorked>40) {
                        double overtime;
                         overtime= (hoursWorked-40)*hourlyRate*2;
                        sum=(hourlyRate*40)+overtime;

                }
                else {
                        sum=hourlyRate*hoursWorked;
                }
                std::cout<<name<<"  has "<<sum<<"   final calculated payout"<<std::endl;
        }
};
class Company {
private:
        std::string companyName;
        std::vector <Employee> staff;
public:
        Company(std::string newCompanyName) {
                companyName=newCompanyName;
        }
        void hireEmployee(std::string empName,double rate,int hours) {
                Employee temp(empName,rate,hours);
                staff.push_back(temp);
        }
        void runPayroll() {
                for (int i=0;i<staff.size();i++) {
                        staff[i].printPaycheck();
                }
        }

};
int main () {
        Company company1("Duel");
        company1.hireEmployee("Bora",15.55,40);
        company1.hireEmployee("Efe",16,50);
        company1.hireEmployee(("Mert"),12.75,-45);
        company1.runPayroll();
        std::cin.ignore((100),'\n');
        std::cin.get();

}