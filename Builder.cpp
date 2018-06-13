//
// Created by xidian on 18-6-10.
//

#include "Builder.h"

void Meal::showItems() {
    for(int i=0;i<food.size();i++){
        std::cout<<"\titem:"<<food[i]->getName();
        std::cout<<"\tpackage:"<<food[i]->getPackage()->getContainer();
        std::cout<<"\tprice:"<<food[i]->getPrice()<<std::endl;
    }

}

float Meal::getTotalPrice() {
    float totalPrice=0.0;
    for(int i=0;i<food.size();i++){
        totalPrice+=food[i]->getPrice();
    }
    return totalPrice;
}

Meal::~Meal() {
    for(long i=food.size()-1;i!=0;i--){
        delete food[i];
    }

}

Meal *VegBuilder::getMeal() {
    Meal* m=new Meal();
    Item* burger=new VegBurger();
    m->addItem(burger);
    Item* drink=new Coca();
    m->addItem(drink);
    return m;
}

Meal *MeatBuilder::getMeal() {
    Meal* m=new Meal();
    Item* burger=new ChickenBurger;
    m->addItem(burger);
    Item* drink=new Spirit();
    m->addItem(drink);
    return m;
}
