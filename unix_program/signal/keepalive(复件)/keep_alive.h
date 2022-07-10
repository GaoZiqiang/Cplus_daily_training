#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include "lst_timer.h" //之前所写的定时器头文件

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

//static sort_timer_list sort_timer_lst;// 声明静态全局对象
extern int pipefd[2];// 初始化问题？
//extern int* getPipefd() {
//
//}

class keep_aliver {
//private:
//    static int *pipefd;

public:
    keep_aliver();
    ~keep_aliver();

//    inline static int* getPipefd() {
//        int ret = socketpair( PF_UNIX, SOCK_STREAM, 0, pipefd );
//        assert( ret != -1 );
//        printf("int keep_aliver, pipefd[0]: %d, pipefd[1]: %d\n", pipefd[0],pipefd[1]);
//
//        return pipefd;
//    }
    int setnonblocking(int fd);
    void addfd( int epollfd, int fd );

    static void addsig( int sig );
    void timer_handler(sort_timer_list &sort_timer_lst, int epollfd);
    static void sig_handler( int sig );
    static void cb_func( client_data* user_data, int epollfd );

};