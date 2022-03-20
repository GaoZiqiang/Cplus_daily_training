// template method设计模式
#include <iostream>

using std::cout, std::endl;

// 应用开发人员
class Application {
public:
    Application() {}
    ~Application() {}

public:
    void step2() {
        cout << "app step2\n";
    }

    void step4() {
        cout << "app step4\n";
    }
};