#include <iostream>
#include "Singleton.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Prototype.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Filter.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"
#include "Proxy.h"


int main() {

    //test singleton
    std::cout << "\n---------- singleton ----------"<<std::endl;
    Singleton *s=Singleton::getInstance();
    std::cout << s<<std::endl;
    delete(s);
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

    //test bridge
    std::cout << "\n---------- bridge ----------"<<std::endl;
    Door* dr=new IronDoor("panda",new IronDoorOP());
    dr->Open();
    dr->Close();

    //test filter
    std::cout << "\n---------- filter ----------"<<std::endl;
    std::vector<Student*>* stu=new std::vector<Student*>;
    stu->push_back((new Student("alice1",'F',99)));
    stu->push_back((new Student("alice2",'F',80)));
    stu->push_back((new Student("alice3",'F',91)));
    stu->push_back((new Student("bob1",'M',90)));
    stu->push_back((new Student("bob2",'M',99)));
    stu->push_back((new Student("bob3",'M',88)));
    stu->push_back((new Student("even1",'M',99)));
    stu->push_back((new Student("even2",'F',80)));
    Class* c1=new Class();
    c1->setmembers(*stu);
    Class* mic=new MaleInClass();
    mic->setmembers(c1);
    Class* fic=new FemaleInClass();
    fic->setmembers(c1);
    Class* tic=new TopStudentsInClass();
    tic->setmembers(c1);
    Class* ab=new AandBinClass(fic,tic);
    showMember(c1->getmembers());
    showMember(mic->getmembers());
    showMember(fic->getmembers());
    showMember(tic->getmembers());
    showMember(ab->getmembers());

    //test composite
    std::cout << "\n---------- composite ----------"<<std::endl;
    Employee* cto=new CTO("alice");
    Employee* cmo=new CMO("bob");
    cto->add(new Engineer("a1"));
    cto->getSalary();
    cmo->getSalary();
    (*(cto->sub))[0]->getSalary();

    //test decorator
    std::cout << "\n---------- decorator ----------"<<std::endl;
    Car* gtr=new GTRCar();
    Decorator* supergtr=new ZJ2EngineDecorator(new GTRCar());
    Decorator* mpvgtr=new ZJ2EngineDecorator(new MPVCar());
    gtr->start();
    supergtr->start();
    mpvgtr->start();

    //test facade
    std::cout << "\n---------- facade ----------"<<std::endl;
    DinnerFacade* df=new DinnerFacade();
    df->doit();
    delete(df);

    //test  flyweight
    std::cout << "\n---------- flyweight ----------"<<std::endl;
    flyweight::CarFactory *cf=new flyweight::CarFactory();
    cf->getCar("GTR","black")->getColor();
    cf->getCar("GTR","white")->getColor();
    cf->getCar("Fode","a")->getColor();
    cf->getCar("GTR","white")->getColor();


    //test  proxy
    std::cout << "\n---------- proxy ----------"<<std::endl;
    proxy::Proxy *proxy1=new proxy::Proxy();
    proxy1->getLocation();
    proxy1->service();
    return 0;
}