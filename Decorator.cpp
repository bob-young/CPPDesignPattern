//
// Created by xidian on 18-6-12.
//

#include <iostream>
#include "Decorator.h"

void GTRCar::start() {
    std::cout<<"GTR launch control start"<<std::endl;
}

void MPVCar::start() {
    std::cout<<"Normal engine start"<<std::endl;
}

Decorator::Decorator(Car* Decorator) {
    this->DecoratedCar=Decorator;

}

void Decorator::start() {
    this->DecoratedCar->start();

}

ZJ2EngineDecorator::ZJ2EngineDecorator(Car *car) : Decorator(car) {

}

void ZJ2EngineDecorator::ZJ2Start() {
    std::cout<<"ZJ2 engine starting"<<std::endl;
}

void ZJ2EngineDecorator::start() {
    Decorator::start();
    ZJ2Start();
}
