// 2个无名管道实现两个进程之间的双向通信

#include "apue.h"

int main() {
    int fds1[2], fds2[2];
    char buf[30];

    int ret = 0;
    ret = pipe(fds1);
    if (ret == -1)
        printf("pipe error\n");
    ret = pipe(fds2);
    if (ret == -1)
        printf("pipe error\n");

    ret = fork();
    if (ret < 0)
        printf("fork error\n");
    else if (ret > 0) {// 父进程
        close(fds1[0]);
        close(fds2[1]);
        while (1) {
            write(fds1[1], "hello", 6);
            sleep(1);

            bzero(buf, sizeof(buf));
            read(fds2[0], buf, sizeof(buf));
            printf("parent: read from child: %s\n", buf);
        }
    } else {// 子进程
        close(fds1[1]);
        close(fds2[0]);
        while (1) {
            bzero(buf, sizeof(buf));
            read(fds1[0], buf, sizeof(buf));
            printf("child: read from parent: %s\n", buf);

            write(fds2[1], "world", 6);
            sleep(1);
        }
    }

}
