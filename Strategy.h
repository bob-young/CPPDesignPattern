//
// Created by xidian on 18-6-25.
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H


#include "Interpreter.h"

class Strategy {
public:
    virtual int operate(int a,int b)=0;

};

class Add:public Strategy{
public:
    int operate(int a,int b);
};

class Sub:public Strategy{
public:
    int operate(int a,int b);
};

class Contexts{
    int param1=0;
    int param2=0;
    Strategy *strategy;
public:
    Contexts(Strategy* s,int p1,int p2);
    void caculate();
    void setStrategy(Strategy *s);
};
#endif //DESIGNPATTERN_STRATEGY_H
