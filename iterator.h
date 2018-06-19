//
// Created by xidian on 18-6-18.
//

#ifndef DESIGNPATTERN_ITERATOR_H
#define DESIGNPATTERN_ITERATOR_H

#include <iostream>
#include <vector>

template<class T>
class iterator {
public:
    virtual bool has_next()=0;
    virtual T next()=0;
};

template<class T>
class Container :public iterator<T>{
private:

    int myiter;
public:
    Container(){};
    std::vector<T> myvec;
    void add(T t){
        myvec.push_back(t);
    };
    bool has_next();
    T next();
};

template <class T>
bool Container<T>::has_next() {
    if(myiter>=myvec.size())
        return false;
    return true;
}

template <class T>
T Container<T>::next() {
    if(myiter<myvec.size())
        return myvec[myiter++];
    return 0;
}




#endif //DESIGNPATTERN_ITERATOR_H
