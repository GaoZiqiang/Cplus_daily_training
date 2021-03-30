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

// 使用typedef来定义Customer类 Item
typedef Customer Item;

class Queue {// 相当于定义一个数据结构中的Queue队列结构
private:
    // class scope definitions
    // 定义存储结构
    struct Node { Item item;struct Node *next;};// 数据部分是一个Item类型的值
    enum {Q_SIZE = 10};

    // private class members
    // 整个queue的前向指针front和尾指针rear
    Node *front;
    Node *rear;
    int items;// current number of items in Queue
    const int qsize;// maximum number of items in Queue 常量，可以进行初始化，但不能进行赋值操作

//    // preemptive definitions to prevent public copying
//    Queue(const Queue &q) : qsize(0) {}// 成员初始化列表
//    // 重载深度赋值运算符
//    Queue &operator=(const Queue &q) { return *this;}
//    Queue(int qs = Q_SIZE);// create a queue with a qs limit

public:
    // preemptive definitions to prevent public copying

    // 成员初始化列表
    // 特殊的类成员变量赋值方式：qsize变量为const变量，对于const类型的类成员，必须使用这种方法
    // 因此需要在创建对象时，即程序执行函数体内的赋值语句之前完成对const变量qsize的赋值
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