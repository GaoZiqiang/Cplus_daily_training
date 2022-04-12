#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int res = 0;
typedef struct {
    int d1;
    int d2;
}Arg;

void* bcall(void* arg) {
    Arg* r = (Arg*)arg;
    res = r->d1 + r->d2;
    printf("res in bcall = %d\n", res);
//    return (void*)&res;
    return (void*)arg;
}

int main() {
    Arg arg = {1, 2};
    int err;
    pthread_t th;

    if ((err = pthread_create(&th, NULL, bcall, &arg)) != 0) {
        printf("pthread_create err\n");
        return -1;
    }

    /*
    int* result;
    pthread_join(th, (void**)&result);
    printf("result = %lx\n", *(int*)result);
    */

    Arg* result;
    pthread_join(th, (void**)&result);
    printf("result = %d, %d\n", ((Arg*)result)->d1, ((Arg*)result)->d2);
}