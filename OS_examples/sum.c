// 验证内存共享对多线程并发的影响
#include <pthread.h>
#include <stdio.h>

#define PREFIX

long sum;

void* do_sum(void* arg) {
    for (int i = 0; i < 10000000; i++)
        asm volatile(PREFIX "addq $1, %0": "=m"(sum));
}


int main() {
    pthread_t pths[4];
    for (int i = 0; i < 4; ++i) {
        pthread_create(&pths[i], NULL, do_sum, (void*)&i);
        pthread_join(pths[i], NULL);
    }
    printf("final sum: %ld\n", sum);
}