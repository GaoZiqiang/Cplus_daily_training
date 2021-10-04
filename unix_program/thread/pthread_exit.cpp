#include "apue.h"

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

void *newThread1(void *);
void *newThread2(void *);

int main(void)
{
    pthread_t tid1,tid2;
    int err;
    void *retNum;  //用于接收return或pthread_exit返回指针的指针变量

    err= pthread_create(&tid1,NULL,newThread1,NULL);
    err= pthread_create(&tid2,NULL,newThread2,NULL);

    pthread_join(tid1,&retNum);  //二重指针是提供用于接收返回指针的指针变量的地址
    printf("thread1 return %d \n",long(retNum));

    pthread_join(tid2,&retNum);
    printf("thread2 return %d \n",long(retNum));

    sleep(1);
    return 0;
}

void *newThread1(void *arg)
{


    printf("in thread 1. \n");


    return((void *)1);  //情况1.正常返回

}

void *newThread2(void *arg)
{

    printf("in thread 2. \n");

    pthread_exit((void *)3);  //情况2.pthread_exit返回
    //addr 0x03

}

