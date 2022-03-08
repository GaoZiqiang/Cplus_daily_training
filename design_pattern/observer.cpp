// 观察者模式

#include <vector>
#include <iostream>

using namespace std;

// 债主抽象基类
class Credit {
public:
    virtual void takeMoney() = 0;
};

// 贷方抽象基类
class Debit {
public:
    virtual void borrow(Credit* credit) = 0;
    virtual void notifyCredits() = 0;// 通知债主

public:
    vector<Credit*> allCredits;
};

// 贷方
class zhangSan : public Debit {
public:
    void borrow(Credit* credit) override {
        allCredits.push_back(credit);
    }
    void notifyCredits() override {// 依次通知债主
        for (auto& credit : allCredits) credit->takeMoney();
    }
};

// 债主1
class liSi : public Credit {
public:
    void takeMoney() override {
        cout << "lisi comes to take money\n";
    }
};

// 债主2
class wangWu : public Credit {
public:
    void takeMoney() override {
        cout << "wangwu comes to take money\n";
    }
};

int main() {
    zhangSan* zhangsan = new zhangSan();

    zhangsan->borrow(new liSi());
    zhangsan->borrow(new wangWu());
    zhangsan->notifyCredits();
}