// pointer-like class--智能指针
#include <stdio.h>

template <typename T>
class shared_ptr {
public:
    T& operator*() const {
        return *px;
    }

    T* operator->() const {
        return px;
    }

    // 构造函数
    shared_ptr(T* p) : px(p) {}

private:
    T* px;
    long* pn;
};

struct Foo {
    void method(void) { printf("this is a method of Foo\n");}
};

int main() {

    // 使用new Foo()对象的指针作为shared_ptr构造函数的参数，实例化shared_ptr对象
    shared_ptr<Foo> sp(new Foo());

    sp->method();
}