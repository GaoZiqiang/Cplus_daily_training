// 利用数组手动实现vector
// 关键：动态扩容

#include <iostream>
#include <string.h>

using namespace std;

const int MAXSIZE = 3;

class vector {
private:
    int start;
    int end;
    int capacity;

    int* data;

public:
    vector() {
        start = 0;
        end = -1;
        capacity = MAXSIZE;
        data = new int[capacity];
    }

    ~vector() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
        }
    }

    // 扩容
    void aux_capacity() {
        cout << "进行扩容" << endl;
        int new_size = capacity * 2;
        int* new_data = new int[new_size];
        memcpy(new_data, data, sizeof(int)*capacity);// 一定要注意:size为sizeof(int)*capacity
        // 释放原来的元素
        delete data;
        data = new_data;
        capacity = capacity * 2;
    }
    // push
    void push_back(int val) {
        // 扩容
        if (end + 1 >= capacity) {
            aux_capacity();
//            cout << "进行扩容" << endl;
//            int new_size = capacity * 2;
//            int* new_data = new int[new_size];
//            memcpy(new_data, data, sizeof(int)*capacity);// 一定要注意:size为sizeof(int)*capacity
//            data = new_data;
//            capacity = capacity * 2;
        }
        data[++end] = val;
    }

    // insert
    void insert(int pos, int val) {
        // 越界
        if (pos < 0 || pos > end) return;
        // 扩容
        if (end + 1 >= capacity) {
            aux_capacity();
        }

        for (int i = end + 1; i > pos; i--) {
            data[i] = data[i-1];
        }
        data[pos] = val;
        end++;

        return;
    }
    // pop
    int pop_back() {
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
    vector vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << "vec.size(): " << vec.size() << endl;
    cout << "vec.top(): " << vec.top() << endl;
    vec.pop_back();
    cout << "vec.top(): " << vec.top() << endl;
    vec.push_back(5);
    cout << "vec.size(): " << vec.size() << endl;
    cout << "vec.top(): " << vec.top() << endl;
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

    vec.insert(1, 6);
    vec.insert(3, 7);
    vec.insert(2, 8);
    vec.insert(5, 9);
    cout << "vec.size(): " << vec.size() << endl;

    for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

    return 0;
}