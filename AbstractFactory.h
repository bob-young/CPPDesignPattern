//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_ABSTRACTFACTORY_H
#define DESIGNPATTERN_ABSTRACTFACTORY_H


#include <iostream>


//product
class laptop{
public:
    virtual void info()=0;
    laptop();
    virtual ~laptop();
};
class smartphone{
public:
    virtual void info()=0;
    smartphone();
    virtual ~smartphone();
};

class samsungLaptop:public laptop{
public:
    void info(){
        std::cout<<"laptop made by samsung\n";
    }
};
class samsungSmartphone:public smartphone{
public:
    void info(){
        std::cout<<"smartphone made by samsung\n";
    }
};
class appleLaptop:public laptop{
public:
    void info(){
        std::cout<<"laptop made by apple\n";
    }
};
class appleSmartphone:public smartphone{
public:
    void info(){
        std::cout<<"smartphone made by apple\n";
    }
};
//factory
class AbstractFactory {
public:
    virtual smartphone* makePhone()=0;
    virtual laptop* makeLaptop()=0;
    virtual ~AbstractFactory();
};
class samsungFactory:public AbstractFactory{
public:
    smartphone* makePhone(){
        return new samsungSmartphone();
    }
    laptop* makeLaptop(){
        return new samsungLaptop();
    }
};
class appleFactory:public AbstractFactory{
public:
    smartphone* makePhone(){
        return new appleSmartphone();
    }
    laptop* makeLaptop(){
        return new appleLaptop();
    }
};
#endif //DESIGNPATTERN_ABSTRACTFACTORY_H
