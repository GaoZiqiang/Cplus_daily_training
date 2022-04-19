#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <pthread.h>
typedef struct {
    int code;
    double balance;

    /*
     * 为每个账户设置锁 和账户锁定在一起
     * 不设置为全局的 否则可能出现一把锁锁住所有账户 导致并发性降低
     * */
    pthread_mutex_t mutex;
}Account;

// 创建账户
extern Account* create_account(int code, double balance);
// 销毁账户
extern void destroy_account(Account* a);
// 存款
extern double withdraw(Account* a, double amt);
// 取款
extern double deposit(Account* a, double amt);
// 查看余额
extern double get_balance(Account* a);

#endif