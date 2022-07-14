#include <iostream>
#include <stdlib.h>
#include <new>

using namespace std;

int main() {
    int* a;
    try {
        a = new int[100000000000000];
    } catch(const bad_alloc& e) {
        throw e.what();
        cout << "出错了";
        exit(1);
    }
//    int* a = new(std::nothrow) int[100000000000000];
//    if (nullptr == a)
//        cout << "内存分配失败\n";
//    else
//        cout << "内存分配成功\n";
//    a[0] = 1;
//    a[1] = 2;
//    cout << *(a++) << "\n";
//    cout << *a << "\n";
//    int b = 1;
//    if (1 == b)
//        throw 1;
}