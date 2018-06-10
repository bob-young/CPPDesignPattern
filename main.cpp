#include <iostream>
#include "Singleton.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"

class a{
public:
    void print(){
        std::cout<<"print a\n";
    }
};

class b:public a{
public:
    void print(){
        std::cout<<"print b\n";
    }
};
void show (a& s){
    s.print();
}
void show2 (b& s){
    s.print();
}
int main() {
    //test singleton
    Singleton *s=Singleton::getInstance();
    std::cout << s<<std::endl;
    Singleton *ss=Singleton::getInstance();
    std::cout << ss<<std::endl;

    //test factory
    Factory f;
    Product* a=f.getProduct('A');
    Product* b=f.getProduct('B');
    Product* c=f.getProduct('C');
    a->getType();
    b->getType();
    c->getType();

    //test abstract factory
    AbstractFactory* samsung=new samsungFactory();
    AbstractFactory* apple=new appleFactory();
    laptop* laptop1=samsung->makeLaptop();
    laptop* laptop2=apple->makeLaptop();
    smartphone* smartphone1=samsung->makePhone();
    smartphone* smartphone2=apple->makePhone();
    laptop1->info();
    laptop2->info();
    smartphone1->info();
    smartphone2->info();

    //test builder
    Builder* vegBuilder=new VegBuilder();
    Builder* meatBuilder=new MeatBuilder();
    Meal* vegmeal=vegBuilder->getMeal();
    Meal* meatmeal=meatBuilder->getMeal();
    vegmeal->showItems();
    std::cout<<"cost: "<<vegmeal->getTotalPrice()<<std::endl;
    meatmeal->showItems();
    std::cout<<"cost: "<<meatmeal->getTotalPrice()<<std::endl;

    //test prototype
    Prototype* p=new cloneablePrototype();
    p->counter+=100;
    (*(p->ip))+=50;
    Prototype* p2=p->clone();
    p->counter++;
    (*(p2->ip))++;
    std::cout << p->counter<<':'<<p->ip<<':'<<*(p->ip)<<std::endl;
    std::cout << p2->counter<<':'<<p2->ip<<':'<<*(p2->ip)<<std::endl;

    
    return 0;
}