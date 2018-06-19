//
// Created by xidian on 18-6-19.
//

#include "Mediator.h"

MUser::MUser(std::string n) {
    this->name=n;
}

void MUser::sendMsg(std::string msg) {
    Mediator::showMsg(this,msg);
}

void Mediator::showMsg(MUser *u, std::string msg) {
    std::cout<<u->name<<" speak :"<<msg<<std::endl;
}
