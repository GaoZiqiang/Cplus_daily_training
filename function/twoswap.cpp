// twoswap.cpp--模板显式具体化

// 为什么使用模板的显式具体化？
// 答：在某些情况下，即使使用模板重载也无法完全满足新模板函数的需求时，需要提供具体化的函数定义，
// 满足新模板的需求

// 当编译器找到与函数调用匹配的具体化定义时，即将使用该定义，而不再寻找模板。

// C++98标准下的模板具体化方法：
// 1 对于给定的函数名，可以有非模板函数、模板函数和显式具体化模板函数以及他们的重载版本；
// 2 显式具体化的原型和定义应以template<>打头，并用过名称来指出类型；
// 3 具体化优先于常规模板，而非模板函数优先于具体化和常规模板。
// 非模板函数>具体化模板函数>常规模板函数

// 非模板函数、常规模板函数、具体化模板函数示例：
// 非模板函数
//void Swap(job &, job &);
// 常规模板函数
// template <typename T>
// void Swap(T &, T &);
// 具体化模板函数
// template <> void Swap<job> (job &, job &);--template <> void Swap(job &, job &);
#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b);

struct job {
    char name[40];
    double salary;
    int floor;
};

// 具体化模板函数
template <> void Swap<job> (job &j1, job &j2);

void Show(job &j);

int main() {
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    Swap(i,j);
    cout <<"Now i, j = " << i << "," << j << endl;

    job sue = {"Susan",7300.60,7};
    job sidney = {"Sidney",78060.72,9};
    Show(sue);
    Show(sidney);
    Swap(sue,sidney);
    Show(sue);
    Show(sidney);

    return 0;


}

template <typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// 具体化模板函数
template <> void Swap<job> (job &j1, job &j2) {
    double t1;
    int t2;
    // 交换salary
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    // 交换floor
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job &j) {
    cout << "j.name: " << j.name << "\n" << "j.salary: " <<j.salary
    << "\n" << "j.floor: " << j.floor << endl;
}