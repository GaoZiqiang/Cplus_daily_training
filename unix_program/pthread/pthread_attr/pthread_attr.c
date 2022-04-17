// detache分离状态多用于网络通信中

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// 回调函数
void* bcall(void* arg) {
    printf("bcall, th %lx\n", pthread_self());
    return (void*)0;
}

// 获取detachstate状态
void out_state(pthread_attr_t* attr) {
    int detachstate;
    pthread_attr_getdetachstate(attr, &detachstate);
    printf("detachstate = %d\n", detachstate);
}


int main() {
    int err;
    pthread_t th;

    pthread_attr_t attr;
    // 初始化attr
    pthread_attr_init(&attr);

    // 输出attr
    out_state(&attr);

    // 设置线程分离状态为PTHREAD_CREATE_DETACHED
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    out_state(&attr);

    if ((err = pthread_create(&th, &attr, bcall, NULL)) != 0) {
        printf("pthread_create err\n");
        return -1;
    };

    sleep(1);

    if ((err = pthread_join(th, NULL)) != 0) {
        printf("pthread_join err\n");
    };

    printf("th %lx finished\n", th);

    pthread_attr_destroy(&attr);

    return 0;
}