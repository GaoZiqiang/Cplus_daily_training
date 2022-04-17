#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char* argv[]) {
    pthread_mutex_t mutex;

    if (argc < 2) {
        printf("-usage:%s [error|normal|recursive]\n", argv[0]);
        exit(1);
    }

    // 定义互斥锁属性
    pthread_mutexattr_t mutexattr;
    // 初始化互斥锁属性
    pthread_mutexattr_init(&mutexattr);

    // 设置互斥锁类型
    if (!strcmp(argv[1], "error")) {
        pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);
    } else if (!strcmp(argv[1], "normal")) {
        pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_NORMAL);
    } else if (!strcmp(argv[1], "recursive")) {
        pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
    }

    // 初始化互斥信号量
    pthread_mutex_init(&mutex, &mutexattr);

    // 加锁1
    if(pthread_mutex_lock(&mutex) != 0) {
        printf("lock failure\n");
    } else {
        printf("lock success\n");
    }

    // 加锁2
    if(pthread_mutex_lock(&mutex) != 0) {
        printf("lock failure\n");
    } else {
        printf("lock success\n");
    }

    // 解锁
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);

    // 销毁变量
    pthread_mutexattr_destroy(&mutexattr);
    pthread_mutex_destroy(&mutex);

    return 0;
}