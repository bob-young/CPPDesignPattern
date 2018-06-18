//
// Created by xidian on 18-6-14.
//

#include <cstring>
#include "ChainRespomsinility.h"

void ConsoleLogger::WriteLog(std::string str) {
    std::cout << "console out:" << str << std::endl;
}

void ErrorLogger::WriteLog(std::string str) {
    std::cout << "Error out:" << str << std::endl;
}

void IOLogger::WriteLog(std::string str) {
    std::cout << "IO out:" << str << std::endl;

}

ChainRespomsinility::ChainRespomsinility() {
    AbstractLogger* cl=new ConsoleLogger();
    this->start=cl;
    AbstractLogger* el=new ErrorLogger();
    cl->setNextLogger(el);
    AbstractLogger* il=new IOLogger();
    el->setNextLogger(il);

}

void ChainRespomsinility::runChain() {
    AbstractLogger* tmp=start;
    char msg[15]="this is step0";
    std::cout<<sizeof(msg)<<std::endl;
    char i[]="1";
    while(tmp){
        //std::string msg=new()
        tmp->WriteLog(strcat(msg,i));
        tmp=tmp->nextlog;
        i[0]++;
    }
    std::cout<<sizeof(msg)<<std::endl;
}

void AbstractLogger::setNextLogger(AbstractLogger *Logger) {
    this->nextlog=Logger;

}
