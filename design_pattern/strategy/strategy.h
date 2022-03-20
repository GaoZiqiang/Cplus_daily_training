// 策略模式

#include <iostream>

using std::cout;

class Context;

// 抽象基类
class TaxStrategy {
public:
    virtual double calculate(const Context& context) = 0;
    virtual ~TaxStrategy() {}
};

// 具体实现类
class CNTax : public TaxStrategy {
public:
    virtual double calculate(const Context& context) {
        cout << "CNTax::calculate\n";
    }
};

class USTax : public TaxStrategy {
public:
    virtual double calculate(const Context& context) {
        cout << "USTax::calculate\n";
    }
};

class DETax : public TaxStrategy {
public:
    virtual double calculate(const Context& context) {
        cout << "DETax::calculate\n";
    }
};