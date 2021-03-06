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
#include "ChainRespomsinility.h"
#include "Order.h"
#include "Interpreter.h"
#include "iterator.h"
#include "Mediator.h"
#include "Memento.h"
#include "Observer.h"
#include "State.h"
#include "NullObj.h"
#include "Strategy.h"
#include "Template.h"
#include "Visitor.h"
#include "MVC.h"

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

    //test chain of responsibility
    std::cout << "\n---------- chain of responsibility ----------"<<std::endl;
    ChainRespomsinility* cr=new ChainRespomsinility();
    cr->runChain();

    //test order
    std::cout << "\n---------- order ----------"<<std::endl;
    Stock* ns=new Stock("ABC");
    Order* buyStock=new BuyStock(ns);
    Order* sellStock=new SellStock(ns);
    buyStock->execute();
    sellStock->execute();

    //test order
    std::cout << "\n---------- interpreter ----------"<<std::endl;
    std::string teststr1="i am tall and rich";
    std::string teststr2="i am tall and hansome";
    tall_rich_hansome* ts1=new tall_rich_hansome();
    std::cout << ts1->istrs(teststr1) <<std::endl;
    std::cout << ts1->istrs(teststr2) <<std::endl;

    //test iterator
    std::cout << "\n---------- iterator ----------"<<std::endl;
    Container<int> *ct=new Container<int>();

    ct->add(1234);
    ct->add('c');
    ct->add(10);
    while(ct->has_next()){
        std::cout<<ct->next()<<std::endl;
    }

    //test mediator
    std::cout << "\n---------- mediator ----------"<<std::endl;
    MUser* mbob=new MUser("bob");
    mbob->sendMsg("hello world");

    //test memento
    std::cout << "\n---------- memento ----------"<<std::endl;
    Originator *originator=new Originator(1,"first",100);
    originator->setV(2,"second",101);
    originator->show();
    originator->setV(3,"third",1020);
    originator->show();
    originator->rollback();
    std::cout<<"roll back\n";
    originator->rollback();
    originator->show();

    //test Observer
    std::cout << "\n---------- Observer ----------"<<std::endl;
    Object* object=new Object();
    Observer_A *oa=new Observer_A(object);
    Observer_B *ob=new Observer_B(object);
    object->setState(100);
    delete ob;

    //test state
    std::cout << "\n---------- state ----------"<<std::endl;
    ContextImp* context=new ContextImp();
    StateImp* start=new Start();
    StateImp* stop=new Stop();
    start->doAction(context);
    stop->doAction(context);

    //test NULLOBJ
    std::cout << "\n---------- null object ----------"<<std::endl;
    RealObjFactory* rof=new RealObjFactory();
    AbstractObj* ao1=rof->productObj("aaa");
    AbstractObj* ao2=rof->productObj("nnn");
    AbstractObj* ao3=rof->productObj("f");
    std::cout<<ao1->getName()<<std::endl;
    std::cout<<ao2->getName()<<std::endl;
    std::cout<<ao3->getName()<<std::endl;

    //test strategy
    std::cout << "\n---------- strategy ----------"<<std::endl;
    Strategy *add=new Add();
    Contexts *context1=new Contexts(add,10,20);
    context1->caculate();
    Strategy *sub=new Sub();
    context1->setStrategy(sub);
    context1->caculate();

    //test template
    std::cout << "\n---------- template ----------"<<std::endl;
    FootballGame *footballGame=new FootballGame();
    BasketballGame *basketballGame=new BasketballGame();
    footballGame->play();
    basketballGame->play();

    //test template
    std::cout << "\n---------- visitor ----------"<<std::endl;
    Computer computer;
    computer.accept(new VisitorImp());


    //test template
    std::cout << "\n---------- MVC ----------"<<std::endl;
    {
        using namespace MVC;
        StudentInfo studentInfo={20,"haha",2,'F'};
        StudentModel* studentModel=new StudentModel(studentInfo);
        StudentView* studentView=new StudentView();
        StudentControl* studentControl=new StudentControl(studentModel,studentView);
        studentControl->Display();
        studentControl->upgrade();
        studentControl->Display();
    }
    return 0;
}