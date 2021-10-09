#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buf[2];
    memset(buf, 0, sizeof(buf));

    // 打开文件
    int fd = open("testfile", O_RDONLY);
    if (-1 == fd)
    {
        perror("open");
        exit(-1);
    }

    printf("fd: %d\n", fd);

    // 读文件
    int total_str_len = 0, str_len = 0;
    while ((str_len = read(fd, buf, sizeof(buf))) > 0)
    {
        if (-1 == str_len)
        {
            perror("read");
            close(fd);
            exit(-1);
        }
        printf("read: %s\n", buf);
        total_str_len += str_len;
    }
//    int str_len = read(fd, buf, sizeof(buf));
//    if (-1 == str_len)
//    {
//        perror("read");
//        close(fd);
//        exit(-1);
//    }
//
//    printf("read: %s\n", buf);
    // 关闭
    close(fd);
}
