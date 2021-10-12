#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int i = 0;

    while (1)
    {
        printf("正在工作...\n");
        if (i == 4)
            abort();// 向自己发送SIGABRT信号--默认终止该进程
        i++;
        sleep(1);
    }

    return 0;
}