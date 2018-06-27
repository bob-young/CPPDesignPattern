//
// Created by xidian on 18-6-27.
//

#include "Template.h"

void Template::play() {
    this->init();
    this->start();
    this->stop();

}

void FootballGame::init() {
    std::cout<<"set 11 players,\t";
}

void FootballGame::start() {
    std::cout<<"play football game,\t";
}

void FootballGame::stop() {
    std::cout<<"goal\n";
}

void BasketballGame::init() {
    std::cout<<"NBA,\t";
}

void BasketballGame::start() {
    std::cout<<"Kobe shoot for 3,\t";
}

void BasketballGame::stop() {
    std::cout<<"Lakers win!\n";
}
