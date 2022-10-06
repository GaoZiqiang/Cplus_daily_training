// shared_ptr使用

#include <bits/stdc++.h>

using namespace std;

int main() {
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // 引用计数+1
    auto pointer3 = pointer; // 引用计数+1
    int *p = pointer.get(); // 这样不会增加引用计数
    cout << "sizeof(pointer) = " << sizeof(pointer) << endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

//    pointer2.reset();
//    std::cout << "reset pointer2:" << std::endl;
//    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
//    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
//    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
//    pointer3.reset();
//    std::cout << "reset pointer3:" << std::endl;
//    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
//    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
//    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset

}
