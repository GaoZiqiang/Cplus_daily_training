#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "account.h"

// 创建账户
Account* create_account(int code, double balance) {
    Account* a = (Account*)malloc(sizeof(Account));

    assert(a != NULL);
    a->code = code;
    a->balance = balance;

    // 对读写锁进行初始化
    pthread_rwlock_init(&a->rwlock, NULL);

    return a;
}

// 销毁账户
void destroy_account(Account* a) {
    assert(a != NULL);

    // 销毁读写锁
    pthread_rwlock_destroy(&a->rwlock);
    free(a);

    return;
}

// 存款
double withdraw(Account* a, double amt) {
    assert(a != NULL);

    // 对账户加写锁
    pthread_rwlock_wrlock(&a->rwlock);
    if (amt < 0 || amt > a->balance) {
        // 释放锁
        pthread_rwlock_unlock(&a->rwlock);
        return 0.0;
    }

    double balance = a->balance;
    sleep(1);
    balance -= amt;
    a->balance = balance;

    // 释放锁
    pthread_rwlock_unlock(&a->rwlock);

    return amt;
}

// 取款
double deposit(Account* a, double amt) {
    assert(a != NULL);

    // 对账户加写锁
    pthread_rwlock_wrlock(&a->rwlock);

    if (amt < 0) {
        // 释放锁
        pthread_rwlock_unlock(&a->rwlock);
        return 0.0;
    }

    double balance = a->balance;
    sleep(1);
    balance += amt;
    a->balance = balance;

    // 释放锁
    pthread_rwlock_unlock(&a->rwlock);

    return amt;
}
// 查看余额
double get_balance(Account* a) {
    assert(a != NULL);

    // 对账户加读锁
    pthread_rwlock_rdlock(&a->rwlock);

    double balance = a->balance;

    // 释放锁
    pthread_rwlock_unlock(&a->rwlock);

    return balance;
}
