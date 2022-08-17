#include <iostream>

using namespace std;

const int a = 10;// 静态存储区

int main() {
    const int c = 3;// 该变量位于栈区
    int* p = (int*)& c;
    *p = 4;
    //在编译的时候c被替换成了3，无法使用通过内存修改后的值
    //*p表示c被修改后的值
    cout << c << " " << *p << endl;

    int* pa = (int*)&a;
    *pa = 15;

    cout << a << " " << *pa << endl;
}