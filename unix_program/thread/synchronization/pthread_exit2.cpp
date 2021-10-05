// threads/badexit2.c 11-3
#include "apue.h"
#include <pthread.h>

struct foo {
    int a;
    int b;
    int c;
    int d;
};
// struct foo foo;// 定义struct foo为全局变量

void printfoo(const char *s, const struct foo *fp)
{
    printf(s);
    printf("  structure at 0x%x\n", (unsigned int)(long)fp);
    printf("  foo.a = %d\n", fp->a);
    printf("  foo.b = %d\n", fp->b);
    printf("  foo.c = %d\n", fp->c);
    printf("  foo.d = %d\n", fp->d);
}

void * thr_fn1(void *arg)
{

    // 方法一：使用全局变量
//    foo = {1, 2, 3, 4};
//    printfoo("thread 1:\n", &foo);
//    pthread_exit((void *)&foo);

    // 方法二：使用堆
//    struct foo *foo;
//    foo = (struct foo *)malloc(sizeof(struct foo));
//
//    foo->a = 1;
//    foo->b = 2;
//    foo->c = 3;
//    foo->d = 4;
//
//    printfoo("thread 1:\n", foo);
//    pthread_exit((void *)foo);

    // 方法三：使用主线程的栈空间
    struct foo *foo = (struct foo *)arg;
    foo->a = 1;
    foo->b = 2;
    foo->c = 3;
    foo->d = 4;
    printfoo("thread 1:\n", foo);
    pthread_exit((void *)foo);
}

void * thr_fn2(void *arg)
{
    printf("thread 2: ID is %d\n", (int)pthread_self());
    pthread_exit((void *)0);
}

int main(void)
{
    // 方法三：使用主线程栈空间
    struct foo foo;

    int err;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    struct foo* fp;
    //printf("before tid1: 0x%x\n", (unsigned int)(long)fp);

    err = pthread_create(&tid1, NULL, thr_fn1, &foo);
    if (err != 0)
        err_quit("can't create thread 1: %s\n", strerror(err));
    // err = pthread_join(tid1, (void*)&fp);
    err = pthread_join(tid1, (void**)&fp);
    if (err != 0)
        err_quit("can't join with thread 1: %s\n", strerror(err));
    printfoo("after tid1:\n", fp);
    sleep(10);

//    err = pthread_create(&tid3, NULL, thr_fn1, NULL);
//    if (err != 0)
//        err_quit("can't create thread 1: %s\n", strerror(err));
//    // err = pthread_join(tid1, (void*)&fp);
//    err = pthread_join(tid3, (void**)&fp);
//    if (err != 0)
//        err_quit("can't join with thread 1: %s\n", strerror(err));
//    printfoo("after tid3:\n", fp);

//    printf("parent starting second thread\n");
//    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
//    if (err != 0)
//        err_quit("can't create thread 2: %s\n", strerror(err));
//    sleep(1);
//    printfoo("parent:\n", fp);
    exit(0);
}
