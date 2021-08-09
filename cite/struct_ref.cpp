#include <iostream>
#include <string>

struct free_throws {
    std::string name;
    int made;
    int attempts;
    float percent;
};

// 函数声明
void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);
const free_throws & clone(free_throws & ft);
const free_throws & clone2(free_throws & ft);

int main() {
    // partial initializations
    free_throws one = {"If Bran", 13, 14};
    free_throws two = {"An Kn",10, 16};
    free_throws three = {"Mi Ma",7, 9};
    free_throws team = {"Throwgoods",0, 0};

    free_throws dup;

//    set_pc(one);
//    display(one);
//
//    accumulate(team, one);
//    display(team);
//
//    display(accumulate(team, two));


    /*需要注意的问题*/
    // 返回引用时需要注意的问题--返回空引用
    // 测试返回临时变量
//    display(clone(one));
    // 测试使用new分配新内存空间
    display(clone2(one));// 这样隐藏了对new的调用--应该及时释放new申请的内存空间
}

void display(const free_throws & ft) {
    using std::cout;

    cout << "Name: " << ft.name << "\n";
    cout << "Made: " << ft.made << "\n";
    cout << "Attempts: " << ft.attempts << "\n";
    cout << "Percent: " <<ft.percent << "\n";
}

void set_pc(free_throws & ft) {
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws & accumulate(free_throws & target, const free_throws & source) {
    target.attempts += source.attempts;
    target.made += source.attempts;
    set_pc(target);

    return target;
}

/*需要注意的问题*/
// 返回空引用--返回引用时需要注意的问题--不能返回临时变量--函数终止时临时变量会被释放--其所占用的内存单元会被释放
// 解决方法一：return返回对传入的参数的引用
const free_throws & clone(free_throws & ft) {
    free_throws newguy;// 创建临时变量
    newguy = ft;
    return newguy;// 返回临时变量--此时报错：interrupted by signal 11: SIGSEGV--数组访问越界--newguy申请的内存已经被释放/没了
}

// 解决方法二：用new来分配新的存储空间，并返回指向该内存空间的指针
const free_throws & clone2(free_throws & ft) {
    free_throws * pt;// 为新变量分配新的内存空间
    *pt = ft;
    return *pt;// 这样就不会被释放了--存在一个问题：不能及时释放new分配的内存
}

