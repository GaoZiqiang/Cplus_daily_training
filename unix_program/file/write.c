#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *buf = "hello\0\n";

    // 打开文件，没有则创建文件
    int fd = open("testfile", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (-1 == fd)
    {
        perror("open");
        exit(-1);
    }

    printf("fd: %d\n", fd);

    // 循环写入
    int len = 7, str_len = 0, total_str_len = 0;
        while (total_str_len < len)
    {
        str_len = write(fd, buf + total_str_len, 1);
        if (-1 == str_len)
        {
            perror("write");
            close(fd);
            exit(-1);
        }
//        buf += str_len;
//        buf_len -= str_len;
        printf("str_len: %d\n", str_len);
        total_str_len += str_len;
    }

//    int str_len = write(fd, buf, strlen(buf) + 2);
//    if (-1 == str_len)
//    {
//        perror("write");
//        close(fd);
//        exit(-1);
//    }
//    printf("str_len: %d\n", str_len);

    // 关闭
    close(fd);

    return 0;
}