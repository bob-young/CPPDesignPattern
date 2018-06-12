//
// Created by xidian on 18-6-12.
//

#ifndef DESIGNPATTERN_DECORATOR_H
#define DESIGNPATTERN_DECORATOR_H

class Car{
public:
    virtual void start()=0;
};

class MPVCar:public Car{
public:
    void start();
};
class GTRCar:public Car{
public:
    void start();
};

class Decorator :public Car{
protected:
    Car* DecoratedCar;
public:
    Decorator(Car* car);
    void start();
};

class ZJ2EngineDecorator:public Decorator{
    void ZJ2Start();
public:
    ZJ2EngineDecorator(Car* car);
    void start();

};

#endif //DESIGNPATTERN_DECORATOR_H
