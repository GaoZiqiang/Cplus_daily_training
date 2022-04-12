#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// 定义线程清理函数
void clean_fun(void* arg) {
    char* s = (char*)arg;
    printf("clean_fun: %s\n", s);
    return;
}

// 线程回调函数
void* bcall(void* arg) {
    int execute = *(int*)arg;

    pthread_cleanup_push(clean_fun, "first clean_fun");
    pthread_cleanup_push(clean_fun, "second clean_fun");

    printf("pthread running: %lx\n", pthread_self());

    pthread_cleanup_pop(execute);
    pthread_cleanup_pop(execute);

    return (void*)0;
}

int main() {
    int err;
    pthread_t th1, th2;

    int arg1 = 2;// execute参数
    if ((err = pthread_create(&th1, NULL, bcall, (void*)&arg1)) != 0) {
        printf("pthread_create1 err\n");
        return -1;
    }

    int arg2 = 1;
    if ((err = pthread_create(&th2, NULL, bcall, (void*)&arg2) != 0)) {
        printf("pthread_create2 err\n");
        return -1;
    }

    pthread_join(th1, NULL);
    printf("th1 %lx finished\n", th1);
    pthread_join(th2, NULL);
    printf("th2 %lx finished\n", th2);

    return 0;
}