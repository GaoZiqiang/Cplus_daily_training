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
        return true;
    }
    else{
        return false;
    }
}

bool Stack::pop(Item &item) {// 这个函数有点奇怪
    if (top > 0){
        item = items[--top];
        return true;
    }
    else{
        return false;
    }
}