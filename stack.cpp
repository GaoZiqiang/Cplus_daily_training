#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
    top = 0;
}

bool Stack::isempty() const {
    return top == 0;
}

bool Stack::isfull() const {
    return top == MAX;
}

bool Stack::push(const Item &item){
    if (top < MAX){
        items[top++] = item;
        cout << "push successfully!" << endl;
        return true;
    }
    else{
        cout << "push failed!" << endl;
        return false;
    }
}

bool Stack::pop() {// 这个函数有点奇怪
    if (top > 0){
        Item item = items[--top];// 实现两点：一顶指针top减1，二将栈元素items[top]取出

        cout << "pop " << item << " successfully!" << endl;
        return true;
    }
    else{
        if(isempty())
            cout << "pop failed for stack already empty!" << endl;
        else
            cout << "pop failed for other reasons!" << endl;
        return false;
    }
}