// template method设计模式
#include <iostream>

using std::cout, std::endl;

// 库开发人员
class Library {
public:
    Library() {}
    ~Library() {}

public:
    void step1() {
        cout << "lib step1\n";
    }

    void step3() {
        cout << "lib step3\n";
    }

    void step5() {
        cout << "lib step5\n";
    }
};