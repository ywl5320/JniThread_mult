//
// Created by yangw on 2018-5-26.
//

#include "FFmpegDecode.h"

FFmpegDecode::FFmpegDecode() {
    exit = false;
}

FFmpegDecode::~FFmpegDecode() {
}


void *ffdecode(void *data)
{
    FFmpegDecode *fFmpegDecode = static_cast<FFmpegDecode *>(data);
    fFmpegDecode->videoDecode->play();
    fFmpegDecode->audioDecode->play();
    while(!fFmpegDecode->exit)
    {
        LOGE("1、ffmpeg 正在解码 .....");
        sleep(1);
    }
    LOGE("1、ffmpeg 解码退出 .....");
    return 0;
}

void FFmpegDecode::decodec() {

    if(videoDecode == NULL)
    {
        videoDecode = new VideoDecode();
    }
    if(audioDecode == NULL)
    {
        audioDecode = new AudioDecode();
    }
    pthread_create(&thread_ffmpeg, NULL, ffdecode, this);

}

void FFmpegDecode::release() {

    exit = true;
    if(audioDecode != NULL)
    {
        audioDecode->release();
        delete (audioDecode);
        audioDecode = NULL;
    }
    if(videoDecode != NULL)
    {
        videoDecode->release();
        delete (videoDecode);
        videoDecode = NULL;
    }
    pthread_join(thread_ffmpeg, NULL);
    LOGE("1、回收ffmpeg资源")

}


