#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void* bcall(void* arg) {
    printf("bcall, th %lx\n", pthread_self());
    return (void*)0;
}

int main() {
    int err;
    pthread_t th;

    pthread_attr_t attr;
    // 初始化attr
    pthread_attr_init(&attr);

    // 设置attr
//    int detachstate = PTHREAD_CREATE_JOINABLE;
    int detachstate;
    pthread_attr_getdetachstate(&attr, &detachstate);
    printf("detachstate = %d\n", detachstate);

    // 设置线程分离状态为PTHREAD_CREATE_DETACHED
    detachstate = PTHREAD_CREATE_DETACHED;
    pthread_attr_setdetachstate(&attr, detachstate);

    pthread_attr_getdetachstate(&attr, &detachstate);
    printf("second detachstate = %d\n", detachstate);

    if ((err = pthread_create(&th, &attr, bcall, NULL)) != 0) {
        printf("pthread_create err\n");
        return -1;
    };

    sleep(1);

    printf("th %lx finished\n", th);

    return 0;
}