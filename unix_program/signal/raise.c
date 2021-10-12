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
            // raise(SIGTERM);
            kill(getpid(), SIGTERM);// 方法二
        i++;
        sleep(1);
    }

    return 0;
}