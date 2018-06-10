//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_BUILDER_H
#define DESIGNPATTERN_BUILDER_H

#include <iostream>
#include <string>
#include <vector>
class Pack{
public:
    virtual std::string getContainer()=0;
};

class Wrapper : public Pack{
public:
    std::string getContainer(){
        return "wrapper";
    }
};
class Bottle : public Pack{
public:
    std::string getContainer(){
        return "bottle";
    }
};

class Item{
public:
    virtual std::string getName()=0 ;
    virtual float getPrice()=0 ;
    virtual Pack* getPackage()=0;
};


class Burger:public Item{
public:
    Pack* getPackage(){
        return new Wrapper();
    }
};

class Drink:public Item{
public:
    Pack* getPackage(){
        return new Bottle();
    }
};

class VegBurger :public Burger{
public:
    std::string getName(){
        return "vegburger";
    }
    float getPrice(){
        return 10.0;
    }
};
class ChickenBurger:public Burger{
public:
    std::string getName(){
        return "chicken burger";
    }
    float getPrice(){
        return 15.0;
    }
};
class Coca:public Drink{
public:
    std::string getName(){
        return "cocacola";
    }
    float getPrice(){
        return 3.0;
    }
};
class Spirit:public Drink{
public:
    std::string getName(){
        return "spirit";
    }
    float getPrice(){
        return 2.5;
    }
};

class Meal{
    std::vector<Item*> food;
public:
    void addItem(Item* i){
        food.push_back(i);
    }

    float getTotalPrice(){
        float totalPrice=0.0;
        for(int i=0;i<food.size();i++){
            totalPrice+=food[i]->getPrice();
        }
        return totalPrice;
    }
    void showItems(){
        for(int i=0;i<food.size();i++){
            std::cout<<"\titem:"<<food[i]->getName();
            std::cout<<"\tpackage:"<<food[i]->getPackage()->getContainer();
            std::cout<<"\tprice:"<<food[i]->getPrice()<<std::endl;
        }
    }
    ~Meal(){
        for(long i=food.size()-1;i!=0;i--){
            delete food[i];
        }
    }
};
class Builder {
public:
    virtual Meal* getMeal()=0;
};
class VegBuilder:public Builder{
public:
    Meal* getMeal(){
        Meal* m=new Meal();
        Item* burger=new VegBurger();
        m->addItem(burger);
        Item* drink=new Coca();
        m->addItem(drink);
        return m;
    }
};

class MeatBuilder:public Builder{
public:
    Meal* getMeal(){
        Meal* m=new Meal();
        Item* burger=new ChickenBurger;
        m->addItem(burger);
        Item* drink=new Spirit();
        m->addItem(drink);
        return m;
    }
};


#endif //DESIGNPATTERN_BUILDER_H
