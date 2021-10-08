#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    // 1 以只写方式--如果文件存在就直接打开并写入--如果不存在就创建
//    if ((fd = open("txt", O_WRONLY | O_CREAT, 0644)) == -1) {// 0644--0表示为八进制
//        perror("open");
//        exit(-1);
//    }
    // 2 只写方式打开--文件不存在就创建--存在就清空文件内容
//    if ((fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
//        perror("open");
//        exit(-1);
//    }
    // 3 只写方式打开--文件不存在就创建--存在就在文件原来的基础上追加
    if ((fd = open("txt", O_WRONLY | O_CREAT | O_APPEND, 0644)) == -1) {
        perror("open");
        exit(-1);
    }

    printf("fd = %d\n", fd);
    write(fd, "world\n", 6);

    close(fd);
}