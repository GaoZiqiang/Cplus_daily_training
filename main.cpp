#include <iostream>

using namespace std;

int main() {
//    int  var1 = 10;//vard1的值可以随机初始化赋值
//    char var2[10];
//    unsigned long int *addr = reinterpret_cast<unsigned long *>(0x7ffff184e358);

    int var = 20;
    int *ip;//定义指针变量

    ip = &var;//在指针变量中存储变量var的地址
    cout << "var的变量值: ";
    cout << var << endl;

    cout << "ip的值: ";//该值为变量var的地址
    cout << ip << endl;

    cout << "*ip的值: ";//该值为变量var的值
    cout << *ip << endl;



//    *addr = 0x12;
//
//    cout << "addr的值：" << endl;
//    cout << addr << endl;//这里出问题了，addr不应该是变量的值吗
//
//    cout << "var1的变量值: ";//该值为随机值
//    cout << var1 << endl;
//
//    cout << "var1 变量的地址： ";//由此可见如果变量未初始化不会出现野指针
//    cout << &var1 << endl;// 变量的地址也是随机改变的
//
//
//
//    cout << "var2 变量的地址： ";
//    cout << &var2 << endl;

    return 0;
}
