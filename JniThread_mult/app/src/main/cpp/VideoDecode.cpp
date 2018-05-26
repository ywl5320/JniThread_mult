//
// Created by yangw on 2018-5-26.
//

#include "VideoDecode.h"

VideoDecode::VideoDecode() {
    exit = false;
}

VideoDecode::~VideoDecode() {

}

void *playvideo(void *data)
{
    VideoDecode *v = static_cast<VideoDecode *>(data);
    while(!v->exit)
    {
        LOGE("2、正在解码视频 ......");
        sleep(1);
    }
    LOGE("2、视频解码退出 ......");
    return 0;
}

void VideoDecode::play() {
    pthread_create(&thread_play, NULL, playvideo, this);
}

void VideoDecode::release() {
    exit = true;
    pthread_join(thread_play, NULL);
    LOGE("2、回收视频资源");
}
