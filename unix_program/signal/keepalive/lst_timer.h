/*************************************************************************
    > File Name: lst_timer.h
    > Author: Torrance_ZHANG
    > Mail: 597156711@qq.com
    > Created Time: Sat 10 Feb 2018 11:39:56 PM PST
 ************************************************************************/

#ifndef _LST_TIMER_H
#define _LST_TIMER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<time.h>
#define BUFFER_SIZE 64

class util_timer;// 前向声明

struct client_data {
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer* timer;
};

class util_timer {
public:
    util_timer() : prev(NULL), next(NULL) {}
public:
    time_t expire;
    void (*cb_func)(client_data*);
    client_data* user_data;
    util_timer* prev;
    util_timer* next;
};

class sort_timer_lst {
public:
    sort_timer_lst() : head(NULL), tail(NULL) {}
    ~sort_timer_lst();
    void add_timer(util_timer* timer);
    void adjust_timer(util_timer* timer);
    void del_timer(util_timer* timer);
    void tick();

private:
    void add_timer(util_timer* timer, util_timer* lst_head);
    util_timer* head;
    util_timer* tail;
};

#endif