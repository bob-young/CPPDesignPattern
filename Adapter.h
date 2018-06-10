//
// Created by xidian on 18-6-10.
//

#ifndef DESIGNPATTERN_ADAPTER_H
#define DESIGNPATTERN_ADAPTER_H

#include <string>
//origin players
class MediaPlayer{
public:
    MediaPlayer();
    virtual void play(std::string type,std::string file)=0;
};


class Mp3Player:public MediaPlayer{
public:
    Mp3Player();
    void play(std::string type,std::string file);
    void play(std::string file);
};
//add players
class AdMediaPlayer{
public:
    virtual void playMp4(std::string file)=0;
    virtual void playVlc(std::string file)=0;
};

class Mp4Player:public AdMediaPlayer{
public:
    Mp4Player();
    void playMp4(std::string file);
    void playVlc(std::string file);
};

class VlcPlayer:public AdMediaPlayer{
public:
    VlcPlayer();
    void playVlc(std::string file);
    void playMp4(std::string file);
};
//adapter
class MediaAdapter : MediaPlayer{
    AdMediaPlayer* amp;
public:
    void play(std::string type,std::string file);
    MediaAdapter(std::string type);
    void play(std::string file){
        amp->playMp4(file);
        amp->playVlc(file);
    }
};

class AudioPlayer:public MediaPlayer{
    MediaAdapter* ma;
public:
    AudioPlayer();
    void play(std::string type,std::string file);
};
class Adapter {

};


#endif //DESIGNPATTERN_ADAPTER_H
