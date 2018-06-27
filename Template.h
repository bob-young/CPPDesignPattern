//
// Created by xidian on 18-6-27.
//

#ifndef DESIGNPATTERN_TEMPLATE_H
#define DESIGNPATTERN_TEMPLATE_H

#include <iostream>

class Template {
public:
    virtual void init()=0;
    virtual void start()=0;
    virtual void stop()=0;
    virtual void play () final ;
};

class FootballGame final:public  Template{
public:
    void init();
    void start();
    void stop();
};

class BasketballGame final:public  Template{
public:
    void init();
    void start();
    void stop();
};
#endif //DESIGNPATTERN_TEMPLATE_H
