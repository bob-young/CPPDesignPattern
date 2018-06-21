//
// Created by xidian on 18-6-21.
//

#include "Observer.h"

void Object::notifyObs() {
    for(int i=0;i<obs->size();i++){
        (*obs)[i]->update();
    }
}

void Object::attachObs(Observer* obr) {
    obs->push_back(obr);
}

void Object::setState(int s) {
    state=s;
    notifyObs();

}

int Object::getState() {
    return state;
}

std::vector<Observer *> *Object::getObs() {
    return obs;
}

Observer_A::Observer_A(Object *obj) {
    this->Obj=obj;
    this->Obj->attachObs(this);
}

void Observer_A::update() {
    std::cout<<"Observer A get:"<<this->Obj->getState()<<std::endl;
}

Observer_A::~Observer_A() {
    std::vector<Observer*> *tmp = Obj->getObs();
    for(int i=0;i<tmp->size();i++){
        if((*tmp)[i]==this){
            (*tmp).erase((*tmp).begin()+i);
        }
    }
}

Observer_B::Observer_B(Object *obj) {
    this->Obj=obj;
    this->Obj->attachObs(this);
}

void Observer_B::update() {
    std::cout<<"Observer B get:"<<this->Obj->getState()<<std::endl;
}

Observer_B::~Observer_B() {
    std::vector<Observer*> *tmp = Obj->getObs();
    for(int i=0;i<tmp->size();i++){
        if((*tmp)[i]==this){
            (*tmp).erase((*tmp).begin()+i);
            std::cout<<"free B"<<std::endl;
        }
    }
}
