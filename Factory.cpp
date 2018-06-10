//
// Created by xidian on 18-6-10.
//

#include <iostream>
#include "Factory.h"

Product* Factory::getProduct(char t){
    std::cout<<"producing "<<t<<std::endl;
    switch (t){
        case 'A':
            return new ProductA();
        case 'B':
            return new ProductB();
        case 'C':
            return new ProductC();
        default:
            return nullptr;
    }
}

void ProductA::getType() {
    std::cout<<"my type is A\n";
}
void ProductB::getType() {
    std::cout<<"my type is B\n";
}
void ProductC::getType() {
    std::cout<<"my type is C\n";
}