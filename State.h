//
// Created by xidian on 18-6-22.
//

#ifndef DESIGNPATTERN_STATE_H
#define DESIGNPATTERN_STATE_H
class State{};

class Context{
public:virtual void setState(State*)=0;
};

class StateImp :public State{
public:
    virtual void doAction(Context* context)=0;

};





class Start:public StateImp{
public:
    void doAction(Context* context);
    Start(){};
};

class Stop:public StateImp{
public:
    void doAction(Context* context);
    Stop(){};
};

class ContextImp:public Context{
private:
    State *state= nullptr;
public:
    ContextImp();
    void setState(State* s);
    State* getState();
};
#endif //DESIGNPATTERN_STATE_H
