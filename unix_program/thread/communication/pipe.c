// 一个无名管道实现两个进程之间的双向通信

#include "apue.h"

int main() {
    int pipe_fds[2];
    char buf[30];

    int ret = pipe(pipe_fds);
    if (ret == -1)
        printf("pipe error\n");

    ret = fork();
    if (ret < 0)
        printf("fork error\n");
    else if (ret > 0) {// 父进程
        // SIG_DFL--发出
        // SIG_IGN--忽略
        // signal(SIGPIPE, SIG_IGN);// 忽略OS发来的警示信号--即使子进程的“读”也关闭了仍旧继续写--否则父进程会停止写
        // close(pipe_fds[0]);// 关闭读
        while (1) {
            write(pipe_fds[1], "hello", 6);
            sleep(2);// 睡的短一点

            bzero(buf, sizeof(buf));
            read(pipe_fds[0], buf, sizeof(buf));
            printf("parent: read from child: %s\n", buf);
        }
    } else {// 子进程
        //close(pipe_fds[1]);// 关闭写
        // close(pipe_fds[0]);// 子进程也将“读”关闭--此时SIGPIPE会让父进程的“写”停止

        while (1) {
            bzero(buf, sizeof(buf));
            int str_len = read(pipe_fds[0], buf, sizeof(buf));
            printf("child: read from parent: %s\n", buf);
            write(pipe_fds[1], "world", 6);
            sleep(3);// 写完再睡
        }
    }

    exit(0);
}