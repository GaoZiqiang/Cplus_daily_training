/*************************************************************************
    > File Name: lst_timer.h
    > Author: Ziqiang_Gao
    > Mail: gaoziqianghi@163.com
    > Created Time: Sat 10 Oct 2021 11:39:56 PM PST
 ************************************************************************/

#ifndef _LST_TIMER_H
#define _LST_TIMER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define BUFFER_SIZE 64

class util_timer;// 前置声明--struct client_data会用到

// 绑定socket和定时器
struct client_data {
    sockaddr_in address;
    int sockfd;// 绑定的客户端sockfd
    char buf[BUFFER_SIZE];
    util_timer* timer;
};

// 一个定时器类--一个定时器是一个类对象
class util_timer {
public:
    util_timer() : prev(NULL), next(NULL) {}
public:
    time_t expire;// !!!到期时间--当前时间加定时时长TIMESLOT
    void (*cb_func)(client_data*, int);// 回调函数
    client_data* user_data;// 客户数据--一个定时器绑定一个client sockfd
    util_timer* prev;
    util_timer* next;
};

// 定时器管理链表
class sort_timer_list {
public:
    sort_timer_list();
    ~sort_timer_list();
    void add_timer(util_timer* timer);
    void adjust_timer(util_timer* timer);
    void del_timer(util_timer* timer);
    void tick(int epollfd);

private:
    void add_timer(util_timer* timer, util_timer* lst_head);
    util_timer* head;
    util_timer* tail;
};

#endif