//
// Created by xidian on 18-6-28.
//

#include "Visitor.h"
/*
void VisitorImp::visit(Computer *computer) {
    std::cout<<"Using computer:"<<computer->info<<std::endl;
}

void VisitorImp::visit(Mouse *mouse) {
    std::cout<<"Using Mouse:"<<mouse->info<<std::endl;
}

void VisitorImp::visit(Keyboard *keyboard) {
    std::cout<<"Using Keyboard:"<<keyboard->info<<std::endl;
}

void VisitorImp::visit(Monitor *monitor) {
    std::cout<<"Using Monitor:"<<monitor->info<<std::endl;
}
*/
Computer::Computer() {
    parts.push_back((new Mouse()));
    parts.push_back((new Keyboard()));
    parts.push_back((new Monitor()));
}

Computer::~Computer() {
    for(int i=0;i<parts.size();i++){
        delete(parts[i]);
    }
}

void Computer::accept(Visitor *visitor) {
    for(int i=0;i<parts.size();i++){
        parts[i]->accept(visitor);
    }
}

void Mouse::accept(Visitor *visitor) {
    visitor->visit(this);
}

void Keyboard::accept(Visitor *visitor) {
    visitor->visit(this);
}

void Monitor::accept(Visitor *visitor) {
    visitor->visit((ComputerPartAbs*)this);
}


void VisitorImp::visit(ComputerPartAbs *computerPart) {
    std::cout<<"Find:"<<computerPart->getinfo()<<std::endl;
}
