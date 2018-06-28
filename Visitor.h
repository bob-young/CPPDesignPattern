//
// Created by xidian on 18-6-28.
//

#ifndef DESIGNPATTERN_VISITOR_H
#define DESIGNPATTERN_VISITOR_H

#include <iostream>
#include <string>
#include <vector>

class ComputerPartAbs{
public:
    std::string info;
    virtual std::string getinfo()=0;
};

class Visitor {
public:
    virtual void visit(ComputerPartAbs* computer)=0;
    /*
    virtual void visit(Mouse* mouse)=0;
    virtual void visit(Keyboard* keyboard)=0;
    virtual void visit(Monitor* monitor)=0;
     */
};

class ComputerPart:public ComputerPartAbs{
public:
    //std::string info;
    virtual void accept(Visitor* visitor)=0;
    virtual std::string getinfo(){};
};

class Computer:public ComputerPart{
public:
    std::string info="HP computer";
    std::vector<ComputerPart*> parts;
    Computer();
    ~Computer();
    void accept(Visitor* visitor);
};

class Mouse:public ComputerPart{
public:
    std::string info="Razer Mouse";
    void accept(Visitor* visitor);
    std::string getinfo(){return info;};
};

class Keyboard:public ComputerPart{
public:
    std::string info="Cherry keyboard";
    void accept(Visitor* visitor);
    std::string getinfo(){return info;};
};

class Monitor:public ComputerPart{
public:
    std::string info="LG monitor";
    void accept(Visitor* visitor);
    std::string getinfo(){return info;};
};
/*
class Visitor {
public:
    virtual void visit(ComputerPart* computer)=0;
    virtual void visit(Mouse* mouse)=0;
    virtual void visit(Keyboard* keyboard)=0;
    virtual void visit(Monitor* monitor)=0;

};
*/
class VisitorImp:public Visitor{
public:
    void visit(ComputerPartAbs* computerPart);
    /*
    void visit(Computer* computer);
    void visit(Mouse* mouse);
    void visit(Keyboard* keyboard);
    void visit(Monitor* monitor);*/
};

#endif //DESIGNPATTERN_VISITOR_H
