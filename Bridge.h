//
// Created by xidian on 18-6-11.
//

#ifndef DESIGNPATTERN_BRIDGE_H
#define DESIGNPATTERN_BRIDGE_H

#include <string>
class OperateDoor{
protected:
    bool isopen=false;
public:
    OperateDoor(){};
    virtual ~OperateDoor(){};
    virtual void Open()=0;
    virtual void Close()=0;
};

class IronDoorOP:public OperateDoor{
public:
    void Open();
    void Close();
};

class Door{
protected:
    OperateDoor *op;
    Door(OperateDoor *op);
public:
    virtual void Open()=0;
    virtual void Close()=0;
    //Door::Door(std::string brand,OperateDoor *op);
    virtual ~Door(){};
};

class IronDoor:public Door{
public:
    IronDoor(std::string brand,OperateDoor* op);
    void Open();
    void Close();
};
class Bridge {

};


#endif //DESIGNPATTERN_BRIDGE_H
