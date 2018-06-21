//
// Created by xidian on 18-6-21.
//

#ifndef DESIGNPATTERN_OBSERVER_H
#define DESIGNPATTERN_OBSERVER_H

#include <iostream>
#include <string>
#include <vector>

class Observer{
public:
    virtual void update()=0;
};

class Object{
private:
    std::vector<Observer*> *obs=new std::vector<Observer*>;
    void notifyObs();
    int state=0;

public:
    void attachObs(Observer* obr);
    void setState(int s);
    int getState();
    std::vector<Observer*>* getObs();

    ~Object(){};//free obs
};

class ObserverImp :public Observer{
protected:
    Object* Obj;
public:
    virtual void update()=0;
};


class Observer_A:public ObserverImp{
public:
    Observer_A(Object* obj);
    void update();
    ~Observer_A();
};

class Observer_B:public ObserverImp{
public:
    Observer_B(Object* obj);
    void update();
    ~Observer_B();
};



#endif //DESIGNPATTERN_OBSERVER_H
