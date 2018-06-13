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

    float getTotalPrice();
    void showItems();
    ~Meal();
};
class Builder {
public:
    virtual Meal* getMeal()=0;
};
class VegBuilder:public Builder{
public:
    Meal* getMeal();
};

class MeatBuilder:public Builder{
public:
    Meal* getMeal();
};


#endif //DESIGNPATTERN_BUILDER_H
