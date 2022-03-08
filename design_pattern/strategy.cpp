// 策略模式--洗衣机模式

#include <iostream>

// strategy抽象基类
class Strategy {
public:
    virtual int doOperation(int num1, int num2) = 0;
};

// 接口的实现类
class operationAdd : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 + num2;
    }
};

class operationSub : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 - num2;
    }
};

// context类
class Context {
private:
    Strategy* strategy;
public:
    Context(Strategy* _stg) : strategy(_stg) {}
public:
    int executeStrategy(int num1, int num2) {
        return strategy->doOperation(num1, num2);
    }
};

int main() {
    Context context(new operationAdd());
    std::cout << context.executeStrategy(1,2) << std::endl;
    Context context2(new operationSub());
    std::cout << context2.executeStrategy(1,2) << std::endl;
}