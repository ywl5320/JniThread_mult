//
// Created by yangw on 2018-5-26.
//

#ifndef JNITHREAD_MULT_FFMPEGDECODE_H
#define JNITHREAD_MULT_FFMPEGDECODE_H


#include "pthread.h"
#include "AndroidLog.h"
#include "unistd.h"
#include "AudioDecode.h"
#include "VideoDecode.h"

class FFmpegDecode {

public:
    AudioDecode *audioDecode = NULL;
    VideoDecode *videoDecode = NULL;
    pthread_t thread_ffmpeg;
    bool exit = false;

public:
    FFmpegDecode();
    ~FFmpegDecode();

    void decodec();
    void release();

};


#endif //JNITHREAD_MULT_FFMPEGDECODE_H
