// 该程序用于验证指针的相关知识点
#include <iostream>

using namespace std;

int main() {


    int var = 20;
    int *ip;//定义指针变量

    ip = &var;//在指针变量中存储变量var的地址
    cout << "var的变量值: ";
    cout << var << endl;

    cout << "ip的值: ";//该值为变量var的地址
    cout << ip << endl;

    cout << "*ip的值: ";//该值为变量var的值
    cout << *ip << endl;

    cout << "over" << endl;

    return 0;
}
