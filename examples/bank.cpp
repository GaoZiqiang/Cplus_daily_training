/*bank.cpp --using the Queue interface*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;// 假设每个小时为60分钟

bool newcustomer(double x);// is there a new customer?

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));// random initializing of rand()

    cout << "Case Study:Bank of Heather Automatic Teller\n";
    cout << "Enter maxium size of queue:\n";// 队列的最大长度
    int qs;
    cin >> qs;
    Queue line(qs);// line queue holds up to qs people

    cout << "Enter the number of simulation hours:\n";// 程序模拟的持续时间
    int hours;
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;// # of cycles

    cout << "Enter the average number of customers per hour\n";// 平均每小时的客户数
    double perhour;// average # of arrival per hour
    cin >> perhour;
    double min_per_cust;// average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;// 平均每隔min_per_cust分钟来一名新用户

    Item temp;// new customer data
    long turnaways = 0;// turned away by full queue 等待排队的customer数量
    long customers = 0;// joined the queue
    long served = 0;// served during the simulation
    long sum_line = 0;// cumulative line length
    int wait_time = 0;// time until autoteller is free
    long line_wait = 0;// cumulative time in line


    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        // 来了新用户
        if (newcustomer(min_per_cust)) {
            if (line.isfull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);// cycle = time of arrival 设置新用户的到达时间和可能的处理时间
                line.enqueue(temp);// add newcustomer to line
            }
        }
        // ATM空闲
        // 若wait_time减小为0，则表示当前没有用户在使用ATM
        // 因此可以将队首的customer取出dequeue，进行ATM服务
        if (wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);// attend next customer
            // 此时新的wait_time就变成了即将进行ATM服务的用户的处理时间process_time
            wait_time = temp.ptime();// for wait_time minutes
            line_wait += cycle - temp.when();
            served++;
        }
        // 当前ATM正忙
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();// 每次循环都要将line.queuecout()计数加一次
    }

    // reporting results
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaways（队列已满，在队列外等待的用户数）:" << turnaways << endl;
        cout << "average queue size（平均每次在排队等待ATM服务的人数）: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "average wait time: " << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

// x = average time,in minutes,between customers
// return value is true if customer shows up this minute
bool newcustomer(double x) {
    // 平均每隔6次，该值会小于1一次
    // 从而能够保证，平均每六分钟来一名新用户
    return (std::rand() * x / RAND_MAX < 1);
}