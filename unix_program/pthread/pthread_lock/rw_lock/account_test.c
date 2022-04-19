#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "account.h"

typedef struct {
    char name[20];
    Account* account;
    double amt;
}OperArg;

// 取款操作的线程运行函数
void* withdraw_fn(void* arg) {
    OperArg* oa = (OperArg*)arg;
    double amt = withdraw(oa->account, oa->amt);

    printf("%8s(0x%lx) withdraw %f from account %d\n",
           oa->name, pthread_self(), amt, oa->account->code);

    return (void*)0;
}

// 存款操作的线程运行函数
void* deposit_fn(void* arg) {
    OperArg* oa = (OperArg*)arg;
    double amt = deposit(oa->account, oa->amt);

    printf("%8s(0x%lx) deposit %f from account %d\n",
           oa->name, pthread_self(), amt, oa->account->code);

    return (void*)0;
}
// 查看余额操作的线程运行函数
void* check_fn(void* arg) {
    return (void*)0;
}

int main() {
    int err;
    pthread_t boy, girl;

    // 创建账户
    Account* a = create_account(100001, 10000);

    OperArg o1, o2;
    strcpy(o1.name, "boy");
    o1.account = a;
    o1.amt = 10000;

    strcpy(o2.name, "girl");
    o2.account = a;
    o2.amt = 10000;

    // 创建两个子线程
    if ((err = pthread_create(&boy, NULL, withdraw_fn, (void*)&o1)) != 0) {
        printf("pthread create error\n");
    }

    if ((err = pthread_create(&girl, NULL, withdraw_fn, (void*)&o2)) != 0) {
        printf("pthread create error\n");
    }


    pthread_join(boy, NULL);
    pthread_join(girl, NULL);

    // 查看账户余额
    printf("account balance: %f\n", get_balance(a));
    // 销毁账户
    destroy_account(a);

    return 0;
}