#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
int main()
{
    int fd;
    char str[32];
    mkfifo("fifo", 0664);           //管道只能实现单向通信,需创建管道文件
    // sscanf(argv[1],"%s",str);//编译写入str

    // 如果只open for reading，会陷入阻塞，until  some  other process opens the same FIFO for writing
    // Opening  a  FIFO  for  reading  normally blocks
    // until  some  other process opens the same FIFO for writing, and vice versa.
    fd = open("fifo",O_WRONLY);//只写且阻塞
    printf("open fd: %d\n", fd);

    if(fd <= 0)
        return 0;
    while (1) {
        write(fd, "hello", 6);
    }
    close(fd);
    exit(0);
}

