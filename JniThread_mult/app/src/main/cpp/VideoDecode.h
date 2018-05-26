//
// Created by yangw on 2018-5-26.
//

#ifndef JNITHREAD_MULT_VIDEODECODE_H
#define JNITHREAD_MULT_VIDEODECODE_H

#include "pthread.h"
#include "AndroidLog.h"
#include "unistd.h"

class VideoDecode {

public:
    bool exit;
    pthread_t thread_play;
public:
    VideoDecode();
    ~VideoDecode();
    void play();
    void release();

};


#endif //JNITHREAD_MULT_VIDEODECODE_H
