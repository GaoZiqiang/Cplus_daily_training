#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void func(int signum)
{
    printf("捕捉到信号: %d\n", signum);
}

int main()
{
    int ret = -1;

    struct itimerval tmo;

    // 配置定时器
    // 设置第一次触发时间
    tmo.it_value.tv_sec = 3;
    tmo.it_value.tv_usec = 0;

    // 设置触发周期
    tmo.it_interval.tv_sec = 2;
    tmo.it_interval.tv_usec = 0;

    // 捕捉超时信号
    signal(SIGALRM, func);
    // 设置定时器
    ret = setitimer(ITIMER_REAL, &tmo, NULL);
    if (-1 == ret)
    {
        perror("setitimer");
        exit(-1);
    }

    printf("按下任意键以继续...\n");
    getchar();// 进程收到定时器超时信号SIGALRM后会终止该进程

    return 0;
}