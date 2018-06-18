//
// Created by xidian on 18-6-14.
//

#include "Interpreter.h"

bool NOT::interpreter(std::string ctx) {
    return ~ n->interpreter(ctx);
}

NOT::NOT(Expression* m) {
    n=m;
}

bool AND::interpreter(std::string ctx) {
    //std::cout << "and\n";
    return left->interpreter(ctx) && right->interpreter(ctx);
}

AND::AND(Expression* l, Expression *r) {
    left=l,right=r;
}

bool OR::interpreter(std::string ctx) {
    //std::cout << "or\n";
    return left->interpreter(ctx) || right->interpreter(ctx);
}

OR::OR(Expression *l, Expression *r) {
    left=l,right=r;
}

META::META(std::string ctx) {
    data=ctx;
}

bool META::interpreter(std::string ctx) {
    if(ctx.find(data)==std::string::npos){
        //std::cout << " 0 \n";
        return false;
    }
    //std::cout << " 1 \n";
    return true;
}
