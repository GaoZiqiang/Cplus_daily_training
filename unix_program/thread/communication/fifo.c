#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char fifo_name1[] = "fifo1", fifo_name2[] = "fifo2";

void signal_fun(int signo);

int main() {
    int wfd, rfd;
    char buf[30];

    // SIGINT--Linux标准信号，键盘输入以中断进程
    signal(SIGINT, signal_fun);
    mkfifo(fifo_name1, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);           //管道只能实现单向通信,需创建管道文件
    mkfifo(fifo_name2, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);           //管道只能实现单向通信,需创建管道文件

    int ret = fork();
    if (ret == -1) {
        printf("fork fail\n");
        exit(-1);
    } else if (ret > 0) {// 父进程
        wfd = open(fifo_name1, O_WRONLY);// 父--写
        rfd = open(fifo_name2, O_RDONLY);// 父--读
        while (1) {
            write(wfd, "hello", 6);
            sleep(3);

            bzero(buf, sizeof(buf));
            read(rfd, buf, sizeof(buf));
            printf("parent: from child: %s\n", buf);
        }
    } else {// 子进程
        rfd = open(fifo_name1, O_RDONLY);// 子--读
        wfd = open(fifo_name2, O_WRONLY);// 子--写
        while (1) {
            bzero(buf, sizeof(buf));
            read(rfd, buf, sizeof(buf));
            printf("child: from parent: %s\n", buf);

            // 上面的读会阻塞下面的写
            write(wfd, "world", 6);
        }
    }

    close(wfd), close(rfd);
}

void signal_fun(int signo) {
    remove(fifo_name1);
    remove(fifo_name2);

    exit(-1);
}