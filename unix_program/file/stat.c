#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int ret = -1;
    struct stat buf;

    ret = stat("lseek_test", &buf);
    if (-1 == ret)
    {
        perror("stat");
        exit(-1);
    }

    printf("st_dev: %lu\n", buf.st_dev);

    return 0;
}