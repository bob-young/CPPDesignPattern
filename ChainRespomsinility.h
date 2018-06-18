//
// Created by xidian on 18-6-14.
//

#ifndef DESIGNPATTERN_CHAINRESPOMSINILITY_H
#define DESIGNPATTERN_CHAINRESPOMSINILITY_H

#include <iostream>
#include <string>

class AbstractLogger{
public:
    AbstractLogger* nextlog= nullptr;
public:
    virtual void WriteLog(std::string str)=0;
    void setNextLogger(AbstractLogger* Logger);
};
class ConsoleLogger:public AbstractLogger{
public:
    void WriteLog(std::string str);
};
class ErrorLogger:public AbstractLogger{
public:
    void WriteLog(std::string str);

};
class IOLogger:public AbstractLogger{
public:
    void WriteLog(std::string str);
};
class ChainRespomsinility {
    AbstractLogger* start= nullptr;
public:
    ChainRespomsinility();
    void runChain();
};


#endif //DESIGNPATTERN_CHAINRESPOMSINILITY_H
