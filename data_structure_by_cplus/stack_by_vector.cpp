#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Stack {
private:
    vector<T> _data;

public:
    Stack() {}

    void push(const T& val) {
        _data.push_back(val);
    }

    T pop() {
        T val = _data.at(_data.size() - 1);
        // 通过iterator迭代器删除
        auto iter = _data.end() - 1;
        _data.erase(iter);
        return val;
    }

    const T& top() const {
        return _data.at(_data.size() - 1);
    }

    bool empty() const {
        return _data.size() == 0;
    }

    T operator[](int pos) {
        if (pos < 0 || pos > _data.size() - 1) return -1;
        return _data.at(pos);
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack[0] << endl;
    cout << stack[2] << endl;
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
}