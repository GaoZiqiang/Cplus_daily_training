#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 回调函数
void* bcall(void* arg) {
    int dist = *(int*)(arg);
    for (int i = 0; i < dist; i++) {
        printf("%lx run %d\n", pthread_self(), i);
        int time = (int)(drand48() * 100000);
        usleep(time);
    }
    return (void*)0;
}

int main() {
    int err;
    pthread_t rabbit, turtle;

    int dist = 10;
    // 创建两个子线程
    if ((err = pthread_create(&rabbit, NULL, bcall, (void*)&dist)) != 0) {
        printf("pthread_create err\n");
        return 0;
    };

    if ((err = pthread_create(&turtle, NULL, bcall, (void*)&dist)) != 0) {
        printf("pthread_create err\n");
        return 0;
    }

    // 阻塞主线程
    pthread_join(rabbit, NULL);
    pthread_join(turtle, NULL);

    printf("main pthread id : %lx\n", pthread_self());
    printf("main finish!\n");

}