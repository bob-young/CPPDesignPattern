//
// Created by xidian on 18-6-20.
//

#include <iostream>
#include "Memento.h"

Originator::Originator(const Originator &c) {

}

Originator *Originator::clone() {

}

void Originator::setV(int v, std::string i, int data) {
    history->push_back(current);
    current=new Memento();
    current->version=v;
    current->info=i;
    current->data=data;
    modify++;
}

Originator::Originator(int v, std::string i, int data) {
    this->current->version=v;
    this->current->info=i;
    this->current->data=data;

}

void Originator::rollback() {
    Memento* tmp=current;
    free(tmp);
    current=(*history)[modify-1];
    history->pop_back();
    modify--;
}

void Originator::show() {
    std::cout<<current->version<<":"<<current->info<<std::endl;

}
