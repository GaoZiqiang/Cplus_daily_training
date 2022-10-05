// 实现方式：
// 引用计数struct封装+SmartPointer友元类

#include <iostream>

using namespace std;

class SmartPointer;

// 引用计数
class _counter {
private:
    _counter(int u) : use(u) {}
    ~_counter() {}

private:
    int use;
    friend class SmartPointer;
};

template<class T>
class SmartPointer {
public:
    SmartPointer(T *t) : pc(new _counter(1)) {
        cout<<"SmartPointer::SmartPointer() invoded use is: "<<pc->use<<endl;
        this->pt = t;
    }

    // 拷贝构造函数
    SmartPointer(SmartPointer<T>& rhs) {
        this->pc = ths.pc;
        this->pt = ths.pt;
        this->pc->use++;
        cout<<"SmartPointer copy invoked use is: "<<pc->use<<endl;
    }

    ~SmartPointer() {
        pc->use--;
        cout<<"SmartPointer::~SmartPointer() invoded use is: "<<pc->use<<endl;
        if (pc->use == 0) {
            delete pt;
            delete pc;
        }
    }

    // 所有权转移
    SmartPointer<T>& operator=(SmartPointer<T> rhs) {
        if (rhs == *this) {
            return *this;
        }

        this->pc->use--;

        if (pc->use == 0) {
            delete pt;
            delete pc;
        }

        this->pt = rhs.pt;
        this->pc = ths.pc;
        this->pc->use++;// 先减再加

        cout<<"SmartPointer::operator=() invoked  use is: "<<pc->use<<endl;

        return *this;
    }

private:
    T *pt;
    _counter* pc;
};