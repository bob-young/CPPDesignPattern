//
// Created by xidian on 18-6-14.
//

#ifndef DESIGNPATTERN_INTERPRETER_H
#define DESIGNPATTERN_INTERPRETER_H

#include <iostream>
#include <string>


class Expression{
public:
    virtual bool interpreter(std::string ctx)=0;
};
class META : public Expression{
public:
    std::string data;
    META(std::string ctx);
    bool interpreter(std::string ctx);
};
class NOT :public Expression{
    Expression* n;
public:
    NOT(Expression* m);
    bool interpreter(std::string ctx);
};

class AND :public Expression{
    Expression* left;
    Expression* right;
public:
    AND(Expression* l,Expression* r);
    bool interpreter(std::string ctx);
};

class OR :public Expression{
    Expression* left;
    Expression* right;
public:
    OR(Expression* l,Expression* r);
    bool interpreter(std::string ctx);
};

class tall_rich_hansome{
public:
    Expression* tall=new META("tall");
    Expression* rich=new META("rich");
    Expression* hansome=new META("handsome");
    Expression* randt=new AND(rich,tall);
    Expression* rands=new AND(rich,hansome);
    Expression* trs=new OR(rands,randt);
    bool istrs(std::string ctx){
        return trs->interpreter(ctx);
    }

};

class Interpreter {

};


#endif //DESIGNPATTERN_INTERPRETER_H
