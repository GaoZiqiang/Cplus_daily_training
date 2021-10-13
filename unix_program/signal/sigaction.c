#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

// 信号处理函数
void fun(int signo)
{
    printf("signal-捕捉到信号: %d\n", signo);
}

// 新的信号处理函数
void fun1(int signo, siginfo_t *info, void *context)
{
        printf("sigaction-捕捉到信号: %d\n", signo);
}

int main()
{
    int ret = -1;

#if 0
    // 设置对信号的处理方式--新的or旧的？
    struct sigaction act;
    // 使用旧的信号处理函数
    act.sa_handler = fun;
    // 标志位为默认 默认使用旧的信号处理函数
    act.sa_flags = 0;
#else
    struct sigaction act;
    // 使用新的信号处理函数
    act.sa_sigaction = fun1;
    // 标志位设置为SA_SIGINFO
    act.sa_flags = SA_SIGINFO;
#endif

    // 信号注册
    ret = sigaction(SIGINT, &act, NULL);
    if (-1 == ret)
    {
        perror("sigaction");
        exit(-1);
    }

    while (1)
    {

    }

    return 0;
}