//
// Created by xidian on 18-6-14.
//

#ifndef DESIGNPATTERN_ORDER_H
#define DESIGNPATTERN_ORDER_H

#include <iostream>
#include <string>
class Order {
public:
    virtual void execute()=0;
};

class Stock{
private:
    std::string name;
    int balance=0;
public:
    Stock(std::string name);
    void sell(int m);
    void buy(int m);
};

class BuyStock:public Order{
private:
    Stock* stock;
public:
    BuyStock(Stock* s);
    void execute();
};

class SellStock:public Order{
private:
    Stock* stock;
public:
    SellStock(Stock* s);
    void execute();
};

#endif //DESIGNPATTERN_ORDER_H
