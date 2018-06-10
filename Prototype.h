//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_PROTOTYPE_H
#define DESIGNPATTERN_PROTOTYPE_H


#include <cstdlib>

class Prototype {
public:
    int *ip=(int*)malloc(sizeof(int));
    int counter=100;
    virtual Prototype* clone()=0;
};

class cloneablePrototype:public Prototype{
public:

    cloneablePrototype();
    Prototype* clone();

private:
    cloneablePrototype(const cloneablePrototype&);//copy
    cloneablePrototype& operator=(cloneablePrototype const& cloneablePrototype1 );//ban on =operator
};

#endif //DESIGNPATTERN_PROTOTYPE_H
