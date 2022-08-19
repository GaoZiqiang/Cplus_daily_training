// 字符串匹配

#include <stdio.h>
#include <string.h>

int main ()
{
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "43a";
    const char *ret;

    ret = strpbrk(str1, str2);
    if(ret)
    {
        printf("第一个匹配的字符是： %c\n", *ret);
    }
    else
    {
        printf("未找到字符");
    }

    return(0);
}