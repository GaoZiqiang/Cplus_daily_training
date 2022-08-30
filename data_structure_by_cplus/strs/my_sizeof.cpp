#include <bits/stdc++.h>

using namespace std;

template<typename T>
int my_sizeof(T t) {
    return (size_t)(&t+1) - (size_t)(&t);
}

int fun1(int i) {
    return i <= 5 ? i : fun1(i-1) * fun1(i-3);
}

int fun2(unsigned int i) {
    return ((i >> 8) ^ 0x2023) | (((i << 8) ^ 0x2023) >> 8);
}



int main() {
    int n = fun2(fun1(101)) % 4;
//    cout << n << endl;
//    int a = 10;
//    cout << my_sizeof<int>(a) << endl;
//
//    char b = 'v';
//    cout << my_sizeof<char>(b) << endl;
//
//    char* c = "fagag";
//    cout << my_sizeof<char*>(c) << endl;
//
//    return 0;
//    int array[5] = {1,2,3};
//
//    cout << array << endl;// 数组名就是首地址
//    cout << array + 1 << endl;// 数组名就是首地址
//    cout << *array << endl;// 对地址进行解析/解引用
//    cout << array[0] << endl;
//    cout << &array[0] << endl;
//    cout << &array[0] + 1 << endl;
//    cout << &array << endl;

    return 0;
}