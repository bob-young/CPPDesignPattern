//
// Created by xidian on 18-6-13.
//

#ifndef DESIGNPATTERN_FLYWEIGHT_H
#define DESIGNPATTERN_FLYWEIGHT_H

#include <string>
#include <hash_map>
namespace __gnu_cxx {
    //hash_map hash_set do not support hash<string>
    //when you input a string,you should cast it to char*,
    //otherwise extend hash<> like this to cast string internally
    template<>
    struct hash<std::string>
    {
        hash<char*> h;
        size_t operator()(const std::string &s) const
        {
            return h(s.c_str());
        };
    };
}

namespace flyweight {
    using namespace __gnu_cxx;

    class Car {
    public:
        virtual void getColor(){};
    };

    class GTR : public Car {
    public:
        std::string color;

        GTR(std::string color);

        void getColor();
    };

    class CarFactory {

        hash_map<std::string, Car* > GTRmapC ;
        hash_map<std::string, Car* > *GTRmap=&GTRmapC;
    public:
        Car *getCar(std::string brand, std::string color);
    };

    class Flyweight {
    public:
    };
}

#endif //DESIGNPATTERN_FLYWEIGHT_H
