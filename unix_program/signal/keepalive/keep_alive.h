/*************************************************************************
    > File Name: keep_alive.h
    > Author: Ziqiang_Gao
    > Mail: gaoziqianghi@163.com
    > Created Time: Sat 10 Oct 2021 11:39:56 PM PST
 ************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include "lst_timer.h"

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

extern int pipefd[2];// 声明extern全局变量

class keep_aliver {
public:
    keep_aliver();
    ~keep_aliver();

    static void get_pipefd();
    int setnonblocking(int fd);
    void addfd( int epollfd, int fd );

    static void addsig( int sig );
    void timer_handler(sort_timer_list &sort_timer_lst, int epollfd);
    static void sig_handler( int sig );
    static void cb_func( client_data* user_data, int epollfd );

};