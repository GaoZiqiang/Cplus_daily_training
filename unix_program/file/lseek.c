#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = -1;
    int ret = -1;
    off_t cur_pos;
    char buf[256];

    // 打开文件--不存在则创建
    fd = open("lseek_test", O_RDWR | O_CREAT, 0644);
    if (-1 == fd)
    {
        perror("open");
        exit(-1);
    }

    // lseek操作
    ret = write(fd, "abcdef", 6);
    if (-1 == ret)
    {
        perror("write");
        close(fd);
        exit(-1);
    }

    // 获取当前偏移量
    cur_pos = lseek(fd, 0, SEEK_CUR);
    printf("cur_pos: %d\n", cur_pos);

    ret = lseek(fd, 10, SEEK_SET);
    if (-1 == ret)
    {
        perror("lseek");
        close(fd);
        exit(-1);
    }

    // 获取当前偏移量
    cur_pos = lseek(fd, 0, SEEK_CUR);
    printf("cur_pos: %d\n", cur_pos);

    ret = write(fd, "123456", 6);
    if (-1 == ret)
    {
        perror("write");
        close(fd);
        exit(-1);
    }

    cur_pos = lseek(fd, 0, SEEK_CUR);
    printf("cur_pos: %d\n", cur_pos);

    // 将文件位置指针指向文件开头--read从文件开头出进行读取--切记
    lseek(fd, 0, SEEK_SET);

    read(fd, buf, 256);
    printf("buf: %s\n", buf);// %s认为遇到尾'\0'就结束了--所以只打印出abcdef

    // 关闭
    close(fd);
}