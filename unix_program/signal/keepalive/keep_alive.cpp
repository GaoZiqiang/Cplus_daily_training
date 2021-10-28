#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#include "keep_alive.h"

int pipefd[2] = {0, 0};// 定义extern全局变量

keep_aliver::keep_aliver() {
    // 这是一种愚蠢的做法--需要依赖类构造器初始化pipefd[2]
    // 定义pipefd[2]--用于两个进程通信的读写通道fd
//    int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, pipefd );
//    assert( ret != -1 );
}

keep_aliver::~keep_aliver() {
}

void keep_aliver::get_pipefd() {
    // 定义pipefd[2]--用于两个进程通信的读写通道fd
    printf("in keep_alive.cpp, pipefd[0]: %d, pipefd[1]: %d\n", pipefd[0],pipefd[1]);
    int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, pipefd );
    assert( ret != -1 );
}

int keep_aliver::setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

void keep_aliver::addfd( int epollfd, int fd )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}

void keep_aliver::sig_handler( int sig )
{
    printf("捕获SIGALRM信号: %d\n", sig);
    int save_errno = errno;
    int msg = sig;
    printf("msg: %d\n", msg);
    int str_len = send( pipefd[1], ( char* )&msg, 1, 0 );// 捕获到超时信号--通过管道发送信息
    printf("send发送成功，str_len = %d\n", str_len);
    errno = save_errno;
}

void keep_aliver::addsig( int sig )
{
    struct sigaction sa;
    memset( &sa, '\0', sizeof( sa ) );
    sa.sa_handler = sig_handler;// 信号处理函数--信号处理函数会开辟一个子进程
    sa.sa_flags |= SA_RESTART;
    sigfillset( &sa.sa_mask );
    // 注册信号sig
    assert( sigaction( sig, &sa, NULL ) != -1 );
}

void keep_aliver::timer_handler(sort_timer_list &sort_timer_lst, int epollfd)
{
    // 方法二：创建sort_timer_lst对象
    // sort_timer_lst sort_timer_lst;
    sort_timer_lst.tick(epollfd);
    // 本次alarm的定时时长TIMESLOT已用完--重新设置一个闹钟
    alarm( TIMESLOT );
}

void keep_aliver::cb_func( client_data* user_data, int epollfd )
{
    epoll_ctl( epollfd, EPOLL_CTL_DEL, user_data->sockfd, 0 );
    assert( user_data );
    close( user_data->sockfd );
    printf( "close fd %d\n", user_data->sockfd );
}
