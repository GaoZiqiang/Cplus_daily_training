// C++编译与链接 参考：https://app.yinxiang.com/Home.action?login=true#n=8557a663-5a64-4c10-a122-07ad2e34dfbf&s=s3&ses=4&sh=2&sds=2&

#include <stdio.h>

extern int gdata;// gdata *UND*
int sum(int, int);// _Z3sumii *UND*

int data = 20;// data g .data

static int sdata;// sdata local
// int data = 20;
int bdata;// bdata g .bss

int main()// main g .text
{
    int a = gdata;
    int b = data;
    
    int ret = sum(a, b);
    
    return 0;
    // printf("Hello World!\n");
}
