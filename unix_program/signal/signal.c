#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void func1(int signum)
{
    printf("捕捉到信号: %d\n", signum);
}

void func2(int signum)
{
    printf("捕捉到信号: %d\n", signum);
}

int main()
{
    // 信号注册
    // Ctrl + C
    signal(SIGINT, func1);

    // Ctrl + \ fa
    signal(SIGQUIT, func2);

    while (1)
    {
        sleep(1);
    }

    return 0;
}