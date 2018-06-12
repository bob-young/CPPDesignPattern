//
// Created by xidian on 18-6-12.
//

#include "Facade.h"

void WashIngredients::doit() {
    std::cout<<"wash ingredients"<<std::endl;
}

void Cook::doit() {
    std::cout<<"cook ingredients"<<std::endl;
}

void Eat::doit() {
    std::cout<<"eat all food"<<std::endl;
}

void WashDishes::doit() {
    std::cout<<"wash dishes"<<std::endl;
}

Facade::Facade() {

}

void Facade::doit() {
    for(int i=0;i<steps->size();i++){
        (*steps)[i]->doit();
    }
}

DinnerFacade::DinnerFacade() {
    this->steps->push_back(new WashIngredients);
    this->steps->push_back(new Cook);
    this->steps->push_back(new Eat);
    this->steps->push_back(new WashDishes);
}

DinnerFacade::~DinnerFacade() {
    std::cout<<"free all"<<std::endl;
    //free all steps
}
