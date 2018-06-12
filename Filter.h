//
// Created by xidian on 18-6-11.
//

#ifndef DESIGNPATTERN_FILTER_H
#define DESIGNPATTERN_FILTER_H

#include <string>
#include <vector>
class Student{
public:
    std::string name;
    char sex;
    int score;

    Student(std::string name,char sex,int score);
    bool operator==(const Student&);
};
class Class{
public:
    std::vector<Student*>* members=new std::vector<Student*>;
    virtual void setmembers( std::vector<Student*> students);
    virtual void setmembers(Class* c);
    virtual std::vector<Student*>* getmembers();
    virtual ~Class(){delete members;}
};

class MaleInClass:public Class{
public:
    virtual void setmembers( std::vector<Student*> students);
    virtual void setmembers(Class* c);
    std::vector<Student*>* getmembers();
};
class FemaleInClass:public Class{
public:
    virtual void setmembers( std::vector<Student*> students);
    virtual void setmembers(Class* c);
    std::vector<Student*>* getmembers();
};
class TopStudentsInClass:public Class{
public:
    virtual void setmembers( std::vector<Student*> students);
    virtual void setmembers(Class* c);
    std::vector<Student*>* getmembers();
};
class AandBinClass :public Class{
    //std::vector<Student>* result=new std::vector<Student>;
public:
    AandBinClass(Class* a, Class *b);
    std::vector<Student*>* getmembers();
};
void showMember(std::vector<Student*> *s);
class Filter {

};


#endif //DESIGNPATTERN_FILTER_H
