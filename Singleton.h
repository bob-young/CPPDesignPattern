//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H


#include <iostream>

class Singleton {
private:
    Singleton(){
        std::cout<<"Create Singleton\n";
    }
    static Singleton* s;
public:
    static Singleton* getInstance(){
        return s;
    }

};


#endif //DESIGNPATTERN_SINGLETON_H
