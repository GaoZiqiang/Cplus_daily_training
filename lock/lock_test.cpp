// 死锁程序测试
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

int data = 1;
mutex mt1,mt2;

void a2() {
	mt2.lock();
	sleep(1);
	data = data * data;
	mt1.lock();  //此时a1已经对mt1上锁，所以要等待
	cout<<data<<endl;
	mt1.unlock();
	mt2.unlock();
}
void a1() {
	mt1.lock();
	sleep(1);
	data = data+1;
	mt2.lock();  //此时a2已经对mt2上锁，所以要等待
	cout<<data<<endl;
	mt2.unlock();
	mt1.unlock();
}

int main() {
	thread t2(a2);
	thread t1(a1);
	
	t1.join();
	t2.join();
	cout<<"main here"<<endl;  //要t1线程、t2线程都执行完毕后才会执行
	return 0;
}

