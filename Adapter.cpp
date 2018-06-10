//
// Created by xidian on 18-6-10.
//

#include <iostream>
#include "Adapter.h"
MediaPlayer::MediaPlayer() {

}
void Mp3Player::play(std::string file) {
    std::cout<<"mp3 player :"<<file<<std::endl;
}

Mp3Player::Mp3Player() {

}

void Mp3Player::play(std::string type, std::string file) {

}

void Mp4Player::playMp4(std::string file) {
    std::cout<<"mp4 player :"<<file<<std::endl;
}

void Mp4Player::playVlc(std::string file) {

}

Mp4Player::Mp4Player() {

}

void VlcPlayer::playVlc(std::string file) {
    std::cout<<"vlc player :"<<file<<std::endl;
}

void VlcPlayer::playMp4(std::string file) {

}

VlcPlayer::VlcPlayer() {

}

MediaAdapter::MediaAdapter(std::string type) {
    if(type.compare("mp4")){
        amp=new Mp4Player();
    }else{
        amp=new VlcPlayer();
    }

}

void MediaAdapter::play(std::string type, std::string file) {

}

void AudioPlayer::play(std::string type, std::string file) {
    if(type.compare("mp3")==0){
        Mp3Player* mp3=new Mp3Player();
        mp3->play(file);
    }else if(type.compare("mp4")==0||type.compare("vlc")==0/*or other types*/){
        ma=new MediaAdapter(type);
        ma->play(file);
    }
}

AudioPlayer::AudioPlayer() {

}


