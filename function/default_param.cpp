// default_param.cpp--函数的默认参数

// 使用默认参数的原因：
// 比如left(string s,int n)函数的作用是返回字符串s的前n个字符，而我们通常/在大多数时候只取前三个字符，
// 这是我们将n设置为3，函数就是left(string s,3)就会比较方便。
// 只有在特殊情况下n会取其他值，这时候n会覆盖掉默认值3

// 函数调用时可以省略默认参数，即不给默认参数赋实参，像这样：left("hello")，等价于left("hello",3)


// 如何实现：
// 在函数原型中声明：--函数定义不需要
// 函数原型
//char * left(const char * str, int n = 3);
// 函数定义--n不用赋初值3
//char * left(const char * str, int n);

// 带参数列表的函数--有多个参数的函数
// 要求：默认参数全部在右边--最右边
//int harpo(int n, int m = 1, int j = 5);// valid
//int groucho(int k = 1, int m = 2, int n = 3);// valid
//int chico(int n, int m = 6, int j);// invalid

// 参数实例化--函数调用--以harpo()函数为例
//beeps = harpo(2);// == harpo(2, 1, 5);
//beeps = harpo(1, 8);// == harpo(1, 8, 5);
//beeps = harpo(8, 7, 6);// === harpo(8, 7, 6);// 没有使用默认参数--全部覆盖了

// 实参从左到右一次赋给实参，不能跳过
//beepa = harpo(3, ,8);// invalid -- not harpo(3, 1, 8);
#include <stdio.h>
#include <iostream>
#include <cstring>

const int ArSize = 80;

char * left(const char * str, int n = 1);

int main() {
//    char * name = {'h','h'};
//    int i = 0;
//    while(name[i]) {
//        printf(name[i]);
//        i++;
//    }
//    printf("size of name: %d",sizeof(name));
    using namespace std;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);
    char *ps = left(sample,4);
    cout << ps << endl;
    delete [] ps;

    ps = left(sample);
    cout << ps << endl;
    delete [] ps;

    return 0;
}

char * left(const char * str, int n) {
//    if(n < 0)
//        n = 0;// 这样除了strlen(str)之外的元素都赋值为空值字符
    int len = strlen(str);
    n = (n < len) ? n : len;

    char * p = new char[n+1];
    int i;
    for (i = 0; i < n && str[i]; i++) {
        p[i] = str[i];
    }
    while(i <= n)
        p[i++] = '\0';

    return p;
}