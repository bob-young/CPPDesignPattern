//
// Created by xidian on 18-6-23.
//

#ifndef DESIGNPATTERN_NULLOBJ_H
#define DESIGNPATTERN_NULLOBJ_H

#include <iostream>
#include <string>
#include <vector>
class AbstractObj{
protected:
    std::string name;
public:
    virtual bool isNull(){};
    virtual std::string getName(){};
};

class NullObj :public AbstractObj{
public:
    std::string getName();
    bool isNUll();
    NullObj();
};

class RealObj :public AbstractObj{
public:
    std::string getName();
    bool isNUll();
    RealObj(std::string name);
};

class RealObjFactory{
public:
    std::vector<std::string> typenames={"aaa","nnn","ddd"};
    AbstractObj* productObj(std::string name);
};
#endif //DESIGNPATTERN_NULLOBJ_H
