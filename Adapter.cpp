//
// Created by xidian on 18-6-10.
//

#include <iostream>
#include "Adapter.h"
MediaPlayer::MediaPlayer() {

}
//void Mp3Player::play(std::string file) {
//    std::cout<<"mp3 player :"<<file<<std::endl;
//}

Mp3Player::Mp3Player() {

}

void Mp3Player::play(std::string type, std::string file) {
    std::cout<<"mp3 player :"<<file<<std::endl;
}

void Mp4Player::play(std::string file) {
    std::cout<<"mp4 player :"<<file<<std::endl;
}


Mp4Player::Mp4Player() {

}

void VlcPlayer::play(std::string file) {
    std::cout<<"vlc player :"<<file<<std::endl;
}



VlcPlayer::VlcPlayer() {

}

MediaAdapter::MediaAdapter(std::string type) {
    //use switch here can be better
    if(type.compare("mp4")==0){
        amp=new Mp4Player();
    }else if(type.compare("vlc")==0){
        amp=new VlcPlayer();
    }else{
        throw "invalid file type in media adapter";
    }

}

void MediaAdapter::play(std::string type, std::string file) {

}

void AudioPlayer::play(std::string type, std::string file) {
    if(type.compare("mp3")==0){//original function
        Mp3Player* mp3=new Mp3Player();
        mp3->play(type,file);
    }else{//adapter
        bool errflag=0;
        try {
            ma=new MediaAdapter(type);
        }catch (const char* msg){
            errflag=1;
            std::cerr<<msg<<std::endl;
        }
        if(errflag){
            std::cout<<"wrong file type\n";
        }else
            ma->play(file);
    }
}

AudioPlayer::AudioPlayer() {

}


