#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

int hello() {
    //std::cout << "Now in hello() before sleep\n";
    //usleep(10000000);
//    for (int j = 0; j < 100000; j++) {
//        i ++;
//        std::cout << i << endl;
//    }
    std::cout << "Now in hello() after sleep\n";
    return 0;

}


struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator() ()
    {
        std::cout << "------ Now in func ------" << std::endl;
        for (unsigned j=0 ; j<1 ; ++j)
        {
            std::cout << "i 的地址: " << &i << std::endl;
            std::cout << "i 的值: " << i << std::endl;
// 1. 潜在访问隐患:悬空引用
        }
    }
};

int main() {
//    std::cout << "start in main\n";
//
//    int some_local_state=0;
//    func my_func(some_local_state);
//    std::thread my_thread(my_func);
//    my_thread.detach();// 使用detach，当主程序运行完时，子线程可能还没运行完，则此时局部变量some_local_state可能已经销毁
//
//    usleep(100);
//    std::cout << "end in main\n";
//    some_local_state = 1;
    std::cout << "start in main\n";
//    // usleep(100000);
//    /*定义thread对象并初始化*/
//    int i = 0;
//    hello(i);
    thread t(hello);// 创建并实例化一个线程，此时线程便已经开始执行
    t.join();

    thread tt();// 线程初始化
//    //t.detach();
//    //usleep(10000000);
//
//
//    //hello();
//    //usleep(10000000);
    std::cout << "end in main\n";
//    /* 在程序结束之前决定是join还是detach
//     * thread.join()：主程序等待子线程运行完再结束
//     * thread.detach()：主程序运行完后就结束，不管子线程是否运行完
//     * */

}