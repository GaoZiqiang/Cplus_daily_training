/*strncpy:将指定长度的字符串复制到字符串数组中*/
#include<stdio.h>
#include<string.h>
#include <iostream>

int main(){
    char name[]={"Chinanet"},destin[20]={};
    strncpy(destin,name,20);
    printf("%s\n",destin);
    std::cout << "length of destin: " << sizeof(destin) << std::endl;
}