#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// 显示文件类型
void showFileType(struct stat *sb);
// 显示文件权限
void showFilePermission(struct stat *sb);

int main(int argc, char *agrv[])
{
    int fd = -1;
    struct stat sb;

    if (2 != argc)
    {
        printf("usage: ./a.out filename\n");
        exit(-1);
    }

    // 获取struct stat
    fd = stat(agrv[1], &sb);
    if (-1 == fd)
    {
        perror("stat");
        exit(-1);
    }

    // 文件类型判断
    showFileType(&sb);
    // 文件权限判断
    showFilePermission(&sb);

    putchar('\n');

    // 关闭
    close(fd);
}

void showFileType(struct stat *sb)
{
    switch(sb->st_mode & S_IFMT)
    {
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("symlink\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown?\n");
            break;
    }
}

void showFilePermission(struct stat *sb)
{
//    if (sb->st_mode & S_IRWXU)
//        printf("rwx");
    if (sb->st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");

    if (sb->st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");

    if (sb->st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
}