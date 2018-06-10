//
// Created by xidian on 18-6-10.
//

#include "Prototype.h"

cloneablePrototype::cloneablePrototype() {

}

Prototype *cloneablePrototype::clone() {
    return new cloneablePrototype(*this);
}
cloneablePrototype:: cloneablePrototype(const cloneablePrototype& c){
    //pass your stack value and heap value here
    counter=c.counter;
    *(ip)=*(c.ip);
}//copy