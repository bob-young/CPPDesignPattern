//
// Created by xidian on 18-6-23.
//

#include "NullObj.h"

std::string NullObj::getName() {
    return "NULL OBJECT!!!";
}

bool NullObj::isNUll() {
    return true;
}

NullObj::NullObj() {

}

std::string RealObj::getName() {
    return name;
}

bool RealObj::isNUll() {
    return false;
}

RealObj::RealObj(std::string name) {
    this->name=name;
}

AbstractObj *RealObjFactory::productObj(std::string namein) {
    for(int i=0;i<typenames.size();i++){
        if(namein.compare(typenames[i])==0){
            return new RealObj(namein);
        }
    }
    return new NullObj();
}
