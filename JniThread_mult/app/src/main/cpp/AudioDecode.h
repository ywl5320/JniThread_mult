//
// Created by yangw on 2018-5-26.
//

#ifndef JNITHREAD_MULT_AUDIODECODE_H
#define JNITHREAD_MULT_AUDIODECODE_H

#include "pthread.h"
#include "AndroidLog.h"
#include "unistd.h"

class AudioDecode {

public:
    bool exit;
    pthread_t thread_play;
public:
    AudioDecode();
    ~AudioDecode();
    void play();
    void release();

};


#endif //JNITHREAD_MULT_AUDIODECODE_H
