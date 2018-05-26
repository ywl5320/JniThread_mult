//
// Created by yangw on 2018-5-26.
//

#include "AudioDecode.h"

AudioDecode::AudioDecode() {
    exit = false;
}

AudioDecode::~AudioDecode() {

}

void *playaudio(void *data)
{
    AudioDecode *a = static_cast<AudioDecode *>(data);
    while(!a->exit)
    {
        LOGE("3、正在解码音频 ......");
        sleep(1);
    }
    LOGE("3、音频解码退出 ......");
    return 0;
}

void AudioDecode::play() {
    pthread_create(&thread_play, NULL, playaudio, this);
}

void AudioDecode::release() {
    exit = true;
    pthread_join(thread_play, NULL);
    LOGE("3、回收音频资源");
}
