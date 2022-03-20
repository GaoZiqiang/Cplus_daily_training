#include "template2_lib.h"

// 应用开发人员
class Application : public Library {
protected:
    // 子类重写父类
    virtual void step2() {
        cout << "app step2\n";
    }

    virtual void step4() {
        cout << "app step4\n";
    }
};