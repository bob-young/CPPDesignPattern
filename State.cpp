//
// Created by xidian on 18-6-22.
//

#include <iostream>
#include "State.h"

void Start::doAction(Context* context) {
    std::cout<<"starting...\n";
    context->setState(this);
}

void Stop::doAction(Context* context) {
    std::cout<<"stop...\n";
    context->setState(this);
}

ContextImp::ContextImp() {

}

void ContextImp::setState(State* s) {
    this->state=s;
}

State *ContextImp::getState() {
    return this->state;
}
