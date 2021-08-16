// twotemps.cpp--重载的模板

// 为什么使用重载的模板？
// 答：并非所有的类型都是用相同的算法，因此，可以像使重载常规函数八样重载模板定义。

// 关键：
// 新旧模板的特征标不同
// (T &, T &)-->(T [], T [], int)// int为非模板类型，为具体类型
#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b);

// 重载模板
template <typename T>
void Swap(T *a, T *b, int n);

void Show(int a[]);

const int Lim = 8;

int main() {
    int i = 10, j =20;
    Swap(i,j);
    cout <<"Now i, j = " << i << "," << j << endl;

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};
    Swap(d1,d2,Lim);
    Show(d1);
    Show(d2);

    return 0;
}

template <typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[]) {
    for (int i = 0; i < Lim; i++)
        cout << a[i];
    cout << endl;
}

