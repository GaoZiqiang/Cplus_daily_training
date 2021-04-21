/*main.cpp --虚拟函数列表与多态实例*/
#include <cstdio>
#include <cstdint>
#include <cstdlib>

class ISpeaker {
protected:
    size_t b;
public:
    ISpeaker(size_t _v) : b(_v) {}
    virtual void speak() = 0;
};

class Dog : public ISpeaker {
public:
    Dog() : ISpeaker(0) {}
    // 实现virtual函数
    virtual void speak() override {
        printf("woof! %llu\n",b);
    }
};

class Human : public ISpeaker {
private:
    size_t c;// 增加一个成员变量
public:
    Human() : ISpeaker(1),c(2) {}
    // 实现virtual函数
    virtual void speak() override {
        printf("hello! %llu\n",c);
    }
};

int main(int argc,char** _argv) {
    Human* pHuman = new Human();
    Dog* pDog = new Dog();

    ISpeaker* speaker1 = (ISpeaker*)pHuman;// 强制类型转换
    ISpeaker* speaker2 = (ISpeaker*)pDog;

    speaker1->speak();
    speaker2->speak();
}