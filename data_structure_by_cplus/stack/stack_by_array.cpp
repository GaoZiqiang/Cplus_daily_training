// 利用数组手动实现stack栈

#include <iostream>
#include <string.h>

using namespace std;

const int MAXSIZE = 3;

class Stack {
private:
    int start;
    int end;
    int capacity;

    int* data;

public:
    Stack() {
        start = 0;
        end = -1;
        capacity = MAXSIZE;
        data = new int[capacity];
    }

    ~Stack() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
        }
    }

    // push
    void push(int val) {
        // 扩容
        if (end + 1 >= capacity) {
//            cout << "进行扩容" << endl;
            int new_size = capacity * 2;
            int* new_data = new int[new_size];
            memcpy(new_data, data, sizeof(int)*capacity);// 一定要注意:size为sizeof(int)*capacity
            data = new_data;
            capacity = capacity * 2;
        }
        data[++end] = val;
    }
    // pop
    int pop() {
        int ans = data[end];
        end--;
        return ans;
    }
    // top
    int top() {
        return data[end];
    }

    // []
    int operator[](int pos) {
        if (pos < 0 || pos > end) return -1;
        return data[pos];
    }

    // size
    int size() {
        return end - start + 1;
    }
};

// 测试
int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "stack.size(): " << stack.size() << endl;
    cout << "stack.top(): " << stack.top() << endl;
    stack.pop();
    cout << "stack.top(): " << stack.top() << endl;
    stack.push(5);
    cout << "stack.size(): " << stack.size() << endl;
    cout << "stack.top(): " << stack.top() << endl;

    for (int i = 0; i < stack.size(); i++) cout << stack[i] << endl;

    return 0;
}