#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fp = fopen("txt", "r");
    if (NULL == fp) {
        printf("errno: %d\n", errno);
        // strerror:根据errno的值，解析出错的原因
        printf("fopen: %s\n", strerror(errno));
        // 根据error值输出错误信息
        // 提示字符串：错误原因
        perror("fopen");
    }
}