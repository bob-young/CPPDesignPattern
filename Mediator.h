//
// Created by xidian on 18-6-19.
//

#ifndef DESIGNPATTERN_MEDIATOR_H
#define DESIGNPATTERN_MEDIATOR_H

#include <iostream>
#include <string>
class MUser{
public:
    std::string name;
    MUser(std::string n);
    void sendMsg(std::string msg);
};
class Mediator {
public:
    static void showMsg(MUser* u,std::string msg);
};


#endif //DESIGNPATTERN_MEDIATOR_H
