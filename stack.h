#include <iostream>
#pragma once

using namespace std;

typedef unsigned long Item;

class Stack{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;

public:
    Stack();// 默认构造器
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);// 为什么要用const来修饰呢？
    bool pop(Item &item);
};