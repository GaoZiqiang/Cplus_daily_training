#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid = -1;

    pid = fork();
    if (-1 == pid)
    {
        perror("fork");
        exit(-1);
    }

    // 子进程
    if (0 == pid)
    {
        while (1)
        {
            printf("子进程在工作...\n");
            sleep(1);
        }
        exit(0);
    }
    else
    {
        sleep(3);
        printf("准备关掉子进程...\n");
        kill(pid, SIGTERM);// 发送SIGTERM信号
        printf("已经关掉子进程\n");
    }

    return 0;
}