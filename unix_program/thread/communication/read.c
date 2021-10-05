#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <errno.h>
int main()
{
    int fd;
    char str[32];
    mkfifo("fifo", 0664);//管道只能实现单向通信,需创建管道文件

    // 如果只open for reading，会陷入阻塞，until  some  other process opens the same FIFO for writing
    // Opening  a  FIFO  for  reading  normally blocks
    // until  some  other process opens the same FIFO for writing, and vice versa.
    fd=open("fifo", O_RDONLY);//只读且阻塞
    printf("open fd: %d\n", fd);

    while(1)
    {
        bzero(str, sizeof(str));
        if((read(fd, str, sizeof(str))) > 0)
            printf("read: %s\n", str);
    }
    close(fd);
}

