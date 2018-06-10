#include <iostream>
#include "Singleton.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Adapter.h"


int main() {

    //test singleton
    std::cout << "\n---------- singleton ----------"<<std::endl;
    Singleton *s=Singleton::getInstance();
    std::cout << s<<std::endl;
    Singleton *ss=Singleton::getInstance();
    std::cout << ss<<std::endl;

    //test factory
    std::cout << "\n---------- factory ----------"<<std::endl;
    Factory f;
    Product* a=f.getProduct('A');
    Product* b=f.getProduct('B');
    Product* c=f.getProduct('C');
    a->getType();
    b->getType();
    c->getType();

    //test abstract factory
    std::cout << "\n---------- abstract factory ----------"<<std::endl;
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
    std::cout << "\n---------- builder ----------"<<std::endl;
    Builder* vegBuilder=new VegBuilder();
    Builder* meatBuilder=new MeatBuilder();
    Meal* vegmeal=vegBuilder->getMeal();
    Meal* meatmeal=meatBuilder->getMeal();
    vegmeal->showItems();
    std::cout<<"cost: "<<vegmeal->getTotalPrice()<<std::endl;
    meatmeal->showItems();
    std::cout<<"cost: "<<meatmeal->getTotalPrice()<<std::endl;

    //test prototype
    std::cout << "\n---------- prototype ----------"<<std::endl;
    Prototype* p=new cloneablePrototype();
    p->counter+=100;
    (*(p->ip))+=50;
    Prototype* p2=p->clone();
    p->counter++;
    (*(p2->ip))++;
    std::cout << p->counter<<':'<<p->ip<<':'<<*(p->ip)<<std::endl;
    std::cout << p2->counter<<':'<<p2->ip<<':'<<*(p2->ip)<<std::endl;

    //test adapter
    std::cout << "\n---------- adapter ----------"<<std::endl;
    AudioPlayer* ap=new AudioPlayer();
    ap->play("mp3","nihao.mp3");
    ap->play("mp4","nihao.mp4");
    ap->play("vlc","nihao.vlc");
    ap->play("vc","nihao.vc");
    return 0;
}