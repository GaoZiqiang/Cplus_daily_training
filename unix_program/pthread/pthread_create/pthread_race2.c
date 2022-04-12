#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 定义结构体参数
typedef struct {
    char name[20];
    int time;
    int start;
    int end;
}race_arg;

void* bcall(void* arg) {
    race_arg* r = (race_arg*)arg;
    for (int i = r->start; i < r->end; i++) {
        printf("%s(%lx) running %d\n", r->name, pthread_self(), i + 1);
        usleep(r->time);
    }
    return arg;
}

int main() {
    int err;
    pthread_t rabbit, turtle;

    // 初始化结构体参数
    race_arg rabbit_arg = {"rabbit", (int)(drand48() * 100000), 20, 50};
    race_arg turtle_arg = {"turtle", (int)(drand48() * 100000), 10, 50};

    if ((err = pthread_create(&rabbit, NULL, bcall, &rabbit_arg)) != 0) {
        printf("pthread_create err\n");
        return 0;
    }

    if ((err = pthread_create(&turtle, NULL, bcall, &turtle_arg)) != 0) {
        printf("pthread_create err\n");
        return 0;
    }

    pthread_join(rabbit, NULL);
    pthread_join(turtle, NULL);

    printf("main pthread id : %lx\n", pthread_self());
    printf("main finish!\n");
}