//
// Created by xidian on 18-6-11.
//

#include <iostream>
#include "Bridge.h"

Door::Door(OperateDoor *op) {
    this->op=op;
}

void IronDoorOP::Open() {
    if(!isopen){
        std::cout<<"open an iron door"<<std::endl;
        isopen= true;
    }else{
        std::cout<<"iron door already open"<<std::endl;
    }

}

void IronDoorOP::Close() {
    if(isopen){
        std::cout<<"close an iron door"<<std::endl;
        isopen= false;
    }else{
        std::cout<<"iron door already close"<<std::endl;
    }

}

IronDoor::IronDoor(std::string brand, OperateDoor* op) :Door(op){
    this->op=op;

}

void IronDoor::Open() {
    op->Open();

}

void IronDoor::Close() {
    op->Close();
}
