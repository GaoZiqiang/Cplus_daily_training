// C++类的this指针
// 总结：this指针==对象的地址

#include <iostream>

class CTest {
public:
    CTest* member_func() {
        std::cout << "this = " << long(this) << std::endl;
        return this;
     }
};

long normal_func(long hidden_this) {
    std::cout << "hidden_this = " << hidden_this << std::endl;
    return hidden_this;
}

int main() {
    CTest test;
    std::cout << "&test = " << long(&test) << std::endl;
    test.member_func();
    normal_func((long)&test);
}