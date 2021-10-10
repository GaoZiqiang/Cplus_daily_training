#include <stdio.h>

int main()
{
    char chars[256];
    int i = 0;

    // 循环读取终端输入/标准输入
    while (1)
    {
        char ch = getchar();
        if (ch == '\n')// 回车即为'\n'
            break;
        chars[i++] = ch;
    }

    printf("chs: %s\n", chars);
}