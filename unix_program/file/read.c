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
    // 只读一次
//    int str_len = read(fd, buf, sizeof(buf));
//    if (-1 == str_len)
//    {
//        perror("read");
//        close(fd);
//        exit(-1);
//    }
//
//    printf("read: %s\n", buf);

    // 循环读取
    char *total_buf = (char*)malloc(sizeof(char) * 100);// 读到的所有内容
    char *tmp_total_buf = total_buf;// 保存total_buf的起始位置
    int total_str_len = 0, str_len = 0;
    while ((str_len = read(fd, buf, sizeof(buf))) > 0)
    {
        if (-1 == str_len)
        {
            perror("read");
            close(fd);
            exit(-1);
        }
        //printf("read: %s\n", buf);
        memcpy(total_buf, buf, str_len);
        total_buf += str_len;// 指针后移
        //total_str_len += str_len;
    }

    printf("total_buf: %s", tmp_total_buf);

    // 关闭
    close(fd);
}
