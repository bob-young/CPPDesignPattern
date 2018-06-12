//
// Created by xidian on 18-6-12.
//

#ifndef DESIGNPATTERN_COMPOSITE_H
#define DESIGNPATTERN_COMPOSITE_H

#include <vector>

class Employee{
public:
    std::string Name;
    Employee(std::string name);
    std::vector<Employee*>* sub=new std::vector<Employee*>;

    virtual void getSalary();
    virtual void add(Employee* e);
};

class CTO:public Employee{
public:
    CTO(std::string name);
    void getSalary();
};
class Engineer:public Employee{
public:
    Engineer(std::string name);
    void getSalary();
};

class CMO:public Employee{
public:
    CMO(std::string);
    void getSalary();
};
class Marketer:public Employee{
public:
    Marketer(std::string name);
    void getSalary();
};
class Composite {

};


#endif //DESIGNPATTERN_COMPOSITE_H
