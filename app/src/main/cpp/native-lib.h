//
// Created by user on 2017/9/7.
//

#ifndef JNIPROTECT_NATIVE_LIB_H
#define JNIPROTECT_NATIVE_LIB_H

#include <sys/select.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>
#include <sys/wait.h>
#include <android/log.h>
#include <sys/types.h>
#include <sys/un.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/signal.h>
#include <android/log.h>
#define LOG_TAG "守护进程 "
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
void create_child();

void start_monitor();

#endif //JNIPROTECT_NATIVE_LIB_H
