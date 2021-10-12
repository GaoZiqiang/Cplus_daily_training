#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    unsigned int ret = 0;

    ret = alarm(5);
    printf("上一次闹钟剩下的时间: %u\n", ret);

    sleep(2);
    // 重新设置闹钟--覆盖原闹钟
    // 此时的ret值为上一个alarm闹钟剩余的second数
    ret = alarm(4);
    printf("上一次闹钟剩下的时间: %u\n", ret);

    printf("按下任意键以继续...\n");
    getchar();

    return 0;
}