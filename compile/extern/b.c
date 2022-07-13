#include<stdio.h>

extern int num;
//num = 10;
void func()
{
    num = 7;
    printf("fun in a.c");
}