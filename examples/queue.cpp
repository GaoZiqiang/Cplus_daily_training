/*queue.cpp --Queue and Customer methods*/
#include "queue.h"
#include <cstdlib> // for rand()

// Queue methods
// 一个奇怪的构造函数
Queue::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    Node * temp;
    while(front != nullptr) {
        temp = front;// temp暂存前向指针front
        front = front->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item &item) {
    if (isfull())
        return false;

    Node *add = new Node;// create node
    add->item = item;// 赋值
    add->next = nullptr;
    items++;// items加1
    if(front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;

    return true;
}

// dequeue
bool Queue::dequeue(Item &item) {
    if (front == nullptr)
        return false;

    item = front->item;// 不太理解 在这里，形参中的item竟然接受赋值
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;

    if (items == 0)
        rear = nullptr;

    return true;
}

// time set to a random value in the range 1 - 3
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;// 到达时间
}
// Customer methods