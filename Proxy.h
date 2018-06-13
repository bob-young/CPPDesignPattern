//
// Created by xidian on 18-6-13.
//

#ifndef DESIGNPATTERN_PROXY_H
#define DESIGNPATTERN_PROXY_H

#include <string>
#include <iostream>
namespace proxy {
    class Bank {
    public:
        std::string location = "???";

        virtual void getLocation() {
            std::cout << this->location << std::endl;
        }

        virtual void service() {};
    };

    class OnlineBank : public Bank {
    public:
        std::string location = "www.bank.com";
        OnlineBank(){std::cout << "build online bank" << std::endl;};
        void service() {
            std::cout << "online bank serves you" << std::endl;
        }
    };

    class Proxy : public Bank {
//now i want to hide the location of the online bank,so use proxy to make online bank private
    private:
        Bank *olb = new OnlineBank();
    public:

        ~Proxy() {free(olb);};

        void getLocation() {
            std::cout << "i will not tell you" << std::endl;
        }

        void service() {
            std::cout << "proxy serves you" << std::endl;
            olb->service();
        }
    };
}

#endif //DESIGNPATTERN_PROXY_H
