//
// Created by xidian on 18-6-12.
//

#ifndef DESIGNPATTERN_FACADE_H
#define DESIGNPATTERN_FACADE_H

#include <iostream>
#include <vector>

class StepsForDinner{
public:
    virtual void doit()=0;
};
class WashIngredients:public StepsForDinner{
public:
    void doit();
};
class Cook:public StepsForDinner{
public:
    void doit();
};
class Eat:public StepsForDinner{
public:
    void doit();
};
class WashDishes:public StepsForDinner{
public:
    void doit();
};
class Facade {
protected:
    std::vector<StepsForDinner*> *steps=new std::vector<StepsForDinner*>;
public:
    Facade();
    void doit();
};
class DinnerFacade:public Facade{
public:
    DinnerFacade();
    ~DinnerFacade();
};

#endif //DESIGNPATTERN_FACADE_H
