#include <jni.h>
#include <string>
#include "native-lib.h"

int userid;
extern "C"
JNIEXPORT void JNICALL
Java_ilouis_me_jniprotect_Watcher_watch(JNIEnv *env, jobject instance, jint user_id) {

    userid = user_id;

    create_child();
}

void create_child() {
    pid_t pid = fork();
    if (pid < 0) {
        LOGE("fork failed");
        exit(1);
    } else if (pid > 0) {
        //do nothing
//        sleep(2);
//        exit(EXIT_SUCCESS);
    } else {
        //fork两次避免产生僵尸进程
        pid_t  p = fork();
        if (p < 0) {
            exit(1);
        } else if(p == 0) {
            sleep(3);
            LOGE("在守护进程");
            start_monitor();
        } else{
            exit(EXIT_SUCCESS);
        }
    }
    if (waitpid(pid, NULL, 0) != pid) {
        exit(1);
    }
}



void *thread_fun(void *args) {
    pid_t pid;
    while ((pid = getppid()) != 1) {
        LOGE("在这停顿2s,等待父进程死亡, %d", pid);
       sleep(2);
    }
    LOGE("父进程已死，唤醒service");
    execlp("am", "am", "startservice", "--user", userid,
           "ilouis.me.jniprotect/ilouis.me.jniprotect.ProtectSerice", (char*)NULL);
}
void start_monitor() {
    pthread_t pthread;
    pthread_create(&pthread, NULL, thread_fun, NULL);
}

