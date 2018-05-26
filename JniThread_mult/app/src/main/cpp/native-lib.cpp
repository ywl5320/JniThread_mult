#include <jni.h>
#include <string>

#include "pthread.h"
#include "FFmpegDecode.h"

FFmpegDecode *fFmpegDecode = NULL;
pthread_t thread_play;

void *playThread(void *data)
{
    FFmpegDecode *ff = static_cast<FFmpegDecode *>(data);
    ff->decodec();
    return 0;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ywl5320_jnithread_1mult_MainActivity_start(JNIEnv *env, jobject instance) {

    // TODO
    if(fFmpegDecode == NULL)
    {
        fFmpegDecode = new FFmpegDecode();
        pthread_create(&thread_play, NULL, playThread, fFmpegDecode);
    }
}extern "C"
JNIEXPORT void JNICALL
Java_com_ywl5320_jnithread_1mult_MainActivity_stop__(JNIEnv *env, jobject instance) {

    // TODO
    if(fFmpegDecode != NULL)
    {
        fFmpegDecode->release();
        pthread_join(thread_play, NULL);
        delete(fFmpegDecode);
        fFmpegDecode = NULL;
    }

}