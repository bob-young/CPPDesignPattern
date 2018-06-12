//
// Created by xidian on 18-6-12.
//

#include <iostream>
#include "Composite.h"

void Employee::getSalary() {
    std::cout<<"get basic salary"<<std::endl;
}

Employee::Employee(std::string name) {
    Name=name;
}

void Employee::add(Employee *e) {
    this->sub->push_back(e);
}

void CTO::getSalary() {
    Employee::getSalary();
    std::cout<<"get cto salary"<<std::endl;
}

CTO::CTO(std::string name) : Employee(name) {

}

void Engineer::getSalary() {
    Employee::getSalary();
    std::cout<<"get engineer salary"<<std::endl;
}

Engineer::Engineer(std::string name) : Employee(name) {

}

void CMO::getSalary() {
    Employee::getSalary();
    std::cout<<"get CMO salary"<<std::endl;
}

CMO::CMO(std::string name) : Employee(name){

}
void Marketer::getSalary() {
    std::cout<<"get Marketing salary"<<std::endl;
}

Marketer::Marketer(std::string name) : Employee(name) {

}
