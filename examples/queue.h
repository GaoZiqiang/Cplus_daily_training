/*queue.h --interface for a queue*/
#ifndef QUEUE_H_
#define QUEUE_H_

class Customer {
private:
    long arrive;
    int processtime;// processing time for customer
public:
    Customer() { arrive = processtime = 0;}
    void set(long when);
    long when() const { return arrive;}
    int ptime() const { return processtime;}
};

typedef Customer Item;

class Queue {
private:
    // class scope definitions
    struct Node { Item item;struct Node *next;};
    enum {Q_SIZE = 10};

    // private class members
    Node *front;
    Node *rear;
    int items;// current number of items in Queue
    const int qsize;// maximum number of items in Queue

//    // preemptive definitions to prevent public copying
//    Queue(const Queue &q) : qsize(0) {}// 成员初始化列表
//    // 重载深度赋值运算符
//    Queue &operator=(const Queue &q) { return *this;}
//    Queue(int qs = Q_SIZE);// create a queue with a qs limit

public:
    // preemptive definitions to prevent public copying
    Queue(const Queue &q) : qsize(0) {}// 成员初始化列表
    // 重载深度赋值运算符
    Queue &operator=(const Queue &q) { return *this;}
    Queue(int qs = Q_SIZE);// create a queue with a qs limit

    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item);// add item to end
    bool dequeue(Item &item);// remove item from front
};
#endif