//
// Created by xidian on 18-6-25.
//

#include "Strategy.h"

int Add::operate(int a, int b) {
    return a+b;
}

int Sub::operate(int a, int b) {
    return a-b;
}

Contexts::Contexts(Strategy *s, int p1, int p2) {
    this->param1=p1;
    this->param2=p2;
    this->strategy=s;
}

void Contexts::caculate() {
    std::cout<<strategy->operate(param1,param2)<<std::endl;
}

void Contexts::setStrategy(Strategy *s) {

    this->strategy=s;
}
