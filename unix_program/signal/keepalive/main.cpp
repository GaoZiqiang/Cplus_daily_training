/*************************************************************************
    > File Name: main.cpp
    > Author: Ziqiang_Gao
    > Mail: gaoziqianghi@163.com
    > Created Time: Sat 10 Oct 2021 11:39:56 PM PST
 ************************************************************************/

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
#include "lst_timer.h"
#include "keep_alive.h"

// 方法二：使用friend函数--需要在main函数中定义
void get_pipefd() {
    printf("in keep_alive.cpp, pipefd[0]: %d, pipefd[1]: %d\n", pipefd[0],pipefd[1]);
    int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, pipefd );
    assert( ret != -1 );
}

// 设置static全局对象
static keep_aliver ka;
static sort_timer_list timer_lst;


int main( int argc, char* argv[] )
{
    if( argc <= 2 )
    {
        printf( "usage: %s ip_address port_number\n", basename( argv[0] ) );
        return 1;
    }
    // 方法一：使用static方法
//    keep_aliver::get_pipefd();
    // 方法二：使用friend函数
    get_pipefd();
    const char* ip = argv[1];
    int port = atoi( argv[2] );

    int ret = 0;
    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int listenfd = socket( PF_INET, SOCK_STREAM, 0 );
    assert( listenfd >= 0 );

    ret = bind( listenfd, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( listenfd, 5 );
    assert( ret != -1 );

    epoll_event events[ MAX_EVENT_NUMBER ];
    // 这里的epollfd？？？
    int epollfd = epoll_create( 5 );
    assert( epollfd != -1 );
    ka.addfd( epollfd, listenfd );

    // 将其设置为全局变量，由keep_aliver初始化
//    ret = socketpair( PF_UNIX, SOCK_STREAM, 0, pipefd );
//    assert( ret != -1 );

    printf("in main, pipefd[0]: %d, pipefd[1]: %d\n", pipefd[0],pipefd[1]);
    ka.setnonblocking( pipefd[1] );
    // 将pipefd[0]--pipe读端注册入epoll例程--专门用来处理SIGALRM信号
    ka.addfd( epollfd, pipefd[0] );

    // add all the interesting signals here
    ka.addsig( SIGALRM );// 设置超时信号捕获器
    ka.addsig( SIGTERM );
    bool stop_server = false;

    // socket和定时器绑定
    client_data* users = new client_data[FD_LIMIT];
    bool timeout = false;
    // 开启alarm
    alarm( TIMESLOT );

    while( !stop_server )
    {
        int number = epoll_wait( epollfd, events, MAX_EVENT_NUMBER, -1 );
        if ( ( number < 0 ) && ( errno != EINTR ) )
        {
            printf( "epoll failure\n" );
            break;
        }

        for ( int i = 0; i < number; i++ )
        {
            int sockfd = events[i].data.fd;
            printf("sockfd: %d\n", sockfd);
            if( sockfd == listenfd )
            {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof( client_address );
                int connfd = accept( listenfd, ( struct sockaddr* )&client_address, &client_addrlength );
                printf("---------------------与新的客户端 %d 建立连接----------\n", connfd);
                ka.addfd( epollfd, connfd );
                // 将socketfd与定时器绑定
                users[connfd].address = client_address;
                users[connfd].sockfd = connfd;
                // 创建一个定时器timer--将定时事件封装成一个定时器timer
                util_timer* timer = new util_timer;
                timer->user_data = &users[connfd];// 将users放入定时器timer
                timer->cb_func = keep_aliver::cb_func;// alarm处理函数
                time_t cur = time( NULL );
                // 建立新连接时设置expire--设置该sockfd到期时间
                timer->expire = cur + 3 * TIMESLOT;
                // 将socketfd与定时器绑定
                users[connfd].timer = timer;
                // 将timer添加到timer链表
                timer_lst.add_timer( timer );
            }
            /*处理信号--pipefd[0]*/
            else if( ( sockfd == pipefd[0] ) && ( events[i].events & EPOLLIN ) )
            {
                int sig;
                char signals[1024];
                // 将从pipe中读取的信号放入signals信号数组
                // 返回值ret为读取到的字符长度
                ret = recv( pipefd[0], signals, sizeof( signals ), 0 );
                if( ret == -1 )
                {
                    // handle the error
                    continue;
                }
                else if( ret == 0 )
                {
                    continue;
                }
                else
                {
                    for( int i = 0; i < ret; ++i )
                    {
                        switch( signals[i] )
                        {
                            case SIGALRM:
                            {
                                // 用timerout标记有定时任务需要处理--但不立即处理--先处理优先度高的任务
                                timeout = true;
                                break;
                            }
                            case SIGTERM:
                            {
                                stop_server = true;
                            }
                        }
                    }
                }
            }
            /*处理客户端连接上接收到的数据*/
            else if(  events[i].events & EPOLLIN )
            {
                memset( users[sockfd].buf, '\0', BUFFER_SIZE );
                // 此为阻塞IO，若该recv阻塞了，则该次for循环便一直阻塞在这里，直到解除阻塞才进行下一轮for循环
                ret = recv( sockfd, users[sockfd].buf, BUFFER_SIZE-1, 0 );
                printf( "get %d bytes of client data %s from client %d\n", ret, users[sockfd].buf, sockfd );
                util_timer* timer = users[sockfd].timer;
                if( ret < 0 )
                {
                    if( errno != EAGAIN )
                    {
                        keep_aliver::cb_func( &users[sockfd], epollfd );
                        if( timer )
                        {
                            // 将该client的socketfd从timer链表中删除
                            timer_lst.del_timer( timer );
                        }
                    }
                }
                else if( ret == 0 )// 对方已关闭--我们也关闭
                {
                    keep_aliver::cb_func( &users[sockfd], epollfd );
                    if( timer )
                    {
                        // 将该client的socketfd从timer链表中删除
                        timer_lst.del_timer( timer );
                    }
                }
                else
                {
                    // 发送给client端口
                    // 异常情况：
                    // ret = send( sockfd, users[sockfd].buf, BUFFER_SIZE-1, 0 );
                    // ret == -1 && errno = EAGAIN--内核写缓冲区满了
                    // 解决方法：
                    // 关注EPOLLOUT事件并添加到epoll空间
//                    struct epoll_event event;
//                    event.events = EPOLLOUT | EPOLLET;// 边缘触发
//                    event.data.fd = sockfd;
//                    // 添加到epoll空间
//                    epoll_ctl(epollfd, EPOLL_CTL_MOD, sockfd, &event);
                    if( timer )
                    {
                        time_t cur = time( NULL );
                        timer->expire = cur + 3 * TIMESLOT;
                        printf( "adjust timer once\n" );
                        // 收到消息--调整TIMESLOT时长--扩大3倍
                        timer_lst.adjust_timer( timer );
                    }
                }
            }
            else
            {
                // others
            }
        }

        if( timeout )
        {
            ka.timer_handler(timer_lst, epollfd);
            timeout = false;// 关闭timeout
        }
    }

    close( listenfd );
    close( pipefd[1] );
    close( pipefd[0] );
    delete [] users;
    return 0;
}
