//
// Created by xidian on 18-6-14.
//

#include "Order.h"

BuyStock::BuyStock(Stock *s) {
    this->stock=s;

}

void BuyStock::execute() {
    this->stock->buy(10);
}

SellStock::SellStock(Stock *s) {
    this->stock=s;
}

void SellStock::execute() {
    this->stock->sell(10);
}

void Stock::sell(int m) {
    if(balance-m<0){
        std::cout<<"you do not have enough money\n";
    }else{
        balance=balance-m;
        std::cout<<"you sell "<<m<<",now your balance is "<<balance<<std::endl;
    }
}

void Stock::buy(int m) {
    balance=balance+m;
    std::cout<<"you buy "<<m<<",now your balance is "<<balance<<std::endl;
}

Stock::Stock(std::string name) {
    this->name=name;
}
