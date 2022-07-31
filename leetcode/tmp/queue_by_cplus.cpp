// C++手动实现queue队列

#include <iostream>

using namespace std;

class Queue {
public:
    Queue(int maxsize_) {
        data = new int[maxsize_+1];
        front = 0;
        rear = 0;
        maxsize = maxsize_;
    }

    ~Queue() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
        }
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        else {
            data[rear] = value;
            rear = (rear + 1) % maxsize;// rear指针指向尾元素的后一个元素
        }
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        else front = (front + 1) % maxsize;
        return true;
    }

    int size() const {
        return (rear - front + maxsize) % maxsize;
    }

    int Front() const {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() const {
        if (isEmpty()) return -1;
        return data[(rear-1+maxsize) % maxsize];// 要加maxsize？
    }

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return (rear + 1) % maxsize == front;
    }

public:
    int* data;
    int front;
    int rear;
    int maxsize;
};

int main() {
    Queue que(10);

    que.enQueue(10);
    que.enQueue(11);
    que.enQueue(12);
    cout << "size = " << que.size() << endl;
    cout << "front = " << que.Front() << endl;
    cout << "rear = " << que.Rear() << endl;
    que.deQueue();
    cout << "after deQueue" << endl;
    cout << "size = " << que.size() << endl;
    cout << "front = " << que.Front() << endl;
    cout << "rear = " << que.Rear() << endl;
}