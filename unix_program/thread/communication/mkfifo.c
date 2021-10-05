#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 100


int creatOpenFifo(char * fifo_name, int mode) {
    int ret = mkfifo(fifo_name, 0664);
    if (ret == -1 && errno != EEXIST) printf("create fail\n");

//    int fd = open(fifo_name, mode);
//    if (fd == -1) printf("open fail\n");

//    printf("fd in open func: %d\n", fd);

    return 0;
}
int main() {
    char fifo_name[] = "./fifo";
    char buf[BUFSIZE];

    int ret = mkfifo(fifo_name, S_IWUSR|S_IRUSR|S_IRGRP|S_IROTH);
    if (ret == -1 && errno != EEXIST) printf("create fail\n");
////    int ret = creatOpenFifo(fifo_name, O_WRONLY);
//    printf("create success\n");

    int fd = open(fifo_name, O_WRONLY);
    if (fd == -1)
        printf("open fail\n");
    else
        printf("open success\n");

    printf("fd: %d\n", fd);

    write(fd, "hello", 6);
    sleep(1);
//    while (1) {
//        // printf("in while\n");
//        // bzero(buf, sizeof(buf));
//        // scanf("enter: %s", buf);
//
//    }

    close(fd);
}