//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_FACTORY_H
#define DESIGNPATTERN_FACTORY_H


class Product{
public:
    virtual void getType(){std::cout<<"base type\n";};
};

class ProductA:public Product {
public:
    void getType();
};

class ProductB:public Product {
public:
    void getType();
};

class ProductC:public Product {
public:
    void getType();
};

class Factory {
public:
    Product* getProduct(char t);

};

#endif //DESIGNPATTERN_FACTORY_H
