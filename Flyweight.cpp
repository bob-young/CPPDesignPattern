//
// Created by xidian on 18-6-13.
//

#include <iostream>
#include "Flyweight.h"

flyweight::GTR::GTR(std::string color) {
    this->color=color;
    std::cout<<"create new GTR in "<<color<<std::endl;
}

void flyweight::GTR::getColor() {
    std::cout<<"GTR in "<<this->color<<std::endl;
}


flyweight::Car *flyweight::CarFactory::getCar(std::string brand, std::string color) {
    //GTRmapC[color];
    if(brand=="GTR"){
        if((GTRmapC)[color]== nullptr){
            (*GTRmap)[color]=new GTR(color);
        }
        return (*GTRmap)[color];
    }else{
        std::cout<<"we do not have this brand\n";
    }

}


