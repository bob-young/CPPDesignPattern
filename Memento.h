//
// Created by xidian on 18-6-20.
//

#ifndef DESIGNPATTERN_MEMENTO_H
#define DESIGNPATTERN_MEMENTO_H

#include "Prototype.h"
#include <string>
#include <vector>

class Memento {
private:

public:
    int version=0;
    std::string info="";
    int data=0;
};

class Originator : public cloneablePrototype{
private:
    int modify=0;
    Originator(const Originator& c);

public:
    Memento* current=new Memento();
    std::vector<Memento*> *history=new std::vector<Memento*>();

    Originator(int v,std::string i, int data);
    void setV(int v,std::string i, int data);
    void rollback();
    void show();
    Originator* clone();
};

#endif //DESIGNPATTERN_MEMENTO_H
