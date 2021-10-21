/*************************************************************************
    > File Name: time_wheel_timer.h
    > Author: Torrance_ZHANG
    > Mail: 597156711@qq.com
    > Created Time: Mon 12 Feb 2018 05:13:13 AM PST
 ************************************************************************/

#ifndef _TIME_WHEEL_TIMER_H
#define _TIME_WHEEL_TIMER_H

#include<time.h>
#include<netinet/in.h>
#include<stdio.h>

#define BUFFER_SIZE 64
class tw_timer;// 前向声明

// 绑定socket和定时器
struct client_data {
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    tw_timer* timer;
};

// 定时器类--单个定时器--一个定时器是一个对象
class tw_timer {
public:
    tw_timer(int rot, int ts) : next(NULL), prev(NULL), rotation(rot), time_slot(ts) {}
public:
    int rotation;// 记录定时器在轮转多少圈后生效/触发
    int time_slot;// 记录定时器位于时间轮上的那个槽--即哪一条子链表
    void (*cb_func)(client_data*);// 定时器回调函数
    client_data* user_data;// 定时器绑定的客户数据--一个定时器绑定一个客户sockfd
    tw_timer* next;// 指向下一个定时器
    tw_timer* prev;// 指向前一个定时器
};

// 定时器管理类--时间轮
class time_wheel {
public:
    time_wheel() : cur_slot(0) {// 初始化时间轮当前指向的槽
        for(int i = 0; i < N; ++ i) {
            slots[i] = NULL;// 初始化每个槽--链表的头结点
        }
    }

    // 遍历每个槽--销毁每个槽对应的定时器链表
    ~time_wheel() {
        for(int i = 0; i < N; i ++) {// N个槽
            tw_timer* tmp = slots[i];
            while(tmp) {// 遍历删除链表
                slots[i] = tmp -> next;
                delete tmp;
                tmp = slots[i];
            }
        }
    }

    // 创建定时器，并将其插入到相应槽的链表中
    tw_timer* add_timer(int timeout) {
        if(timeout < 0) return NULL;
        int ticks = 0;
        // 小于一个槽间隔--向上取整为1
        if(timeout < SI) {
            ticks = 1;
        }
        // 该定时器到触发为止要经过的脉搏tick总数--每隔TIMEOUT 1s为一个脉搏周期
        else ticks = timeout / SI;
        // 通过定时时长确定rotation--在时间轮转动rotations圈后触发和ts--插入时间轮的第ts个槽
        int rotation = ticks / N;
        int ts = (cur_slot + (ticks % N)) % N;
        // 创建新的定时器timer--输入参数为rotation和ts
        tw_timer* timer = new tw_timer(rotation, ts);
        // 第ts个槽中还没有插入定时器，则将该定时器设置为该槽的头节点
        if(!slots[ts]) {
            printf("add timer, rotation is %d, ts is %d, cur_slot is %d\n", rotation, ts, cur_slot);
            slots[ts] = timer;// slots[ts]为该槽链表的头结点
        }
        // 将定时器插入第ts个槽中
        // 链表为无序链表，因此只需要插入在链表头即可
        else {
            printf("add timer, rotation is %d, ts is %d, cur_slot is %d\n", rotation, ts, cur_slot);
            timer -> next = slots[ts];
            slots[ts] -> prev = timer;
            slots[ts] = timer;// 头结点移动到最新插入的节点
        }
        return timer;
    }

    // 删除目标定时器
    void del_timer(tw_timer* timer) {
        if(!timer) return;
        int ts = timer -> time_slot;// ts为该槽链表的头节点的位置
        // 若为头节点--重置槽的头结点--将该节点的下一个节点设置为新的头结点
        if(timer == slots[ts]) {
            slots[ts] = slots[ts] -> next;
            if(slots[ts]) {
                slots[ts] -> prev = NULL;
            }
            delete timer;
        }
        else {
            timer -> prev -> next = timer -> next;
            if(timer -> next) {
                timer -> next -> prev = timer -> prev;
            }
            delete timer;
        }
    }

    // 检查定时器链表中是否有定时器到期
    // 脉搏函数--一个TIMESLOT--1s过去了--查看时间槽中有没有定时器到期了
    void tick() {
        tw_timer* tmp = slots[cur_slot];// 当前槽上链表的头结点
        printf("current slot is %d\n", cur_slot);
        // 遍历槽的整个链表--将rotation为0的节点删除
        while(tmp) {
            printf("tick the timer once\n");
            // 定时器的rotation大于0，则其在这一轮没有到期--再过rotation轮后才到期
            if(tmp -> rotation > 0) {
                tmp -> rotation --;
                // 查看当前槽上链表的下一个节点--看是否到期
                tmp = tmp -> next;
            }
            // 否则，说明当前定时器已经到期，执行定时任务，并删除该定时器
            else {
                // 执行定时任务
                tmp -> cb_func(tmp -> user_data);
                // 从当前槽的链表中删除该定时器
                // 当前定时器为链表头结点
                if(tmp == slots[cur_slot]) {
                    printf("delete header/头结点 in cur_slot\n");
                    slots[cur_slot] = tmp -> next;
                    delete tmp;
                    if(slots[cur_slot]) {
                        slots[cur_slot] -> prev = NULL;
                    }
                    tmp = slots[cur_slot];
                }
                // 不为头结点
                else {
                    tmp -> prev -> next = tmp -> next;
                    if(tmp -> next) {
                        tmp -> next -> prev = tmp -> prev;
                    }
                    tw_timer* tmp2 = tmp -> next;
                    delete tmp;
                    tmp = tmp2;
                }
            }
        }
        // 更新时间轮的当前槽--反映时间轮的转动
        cur_slot = ++cur_slot % N;
    }

private:
    static const int N = 60;// 时间轮上槽的数目
    static const int SI = 1;// 槽间隔--即每1s时间轮转动一次
    // slots[i]:每个槽上的定时器链表--N个槽对应N条链表--链表为无序链表--一个数组
    // 槽==链表
    tw_timer* slots[N];
    int cur_slot;// 时间轮的当前槽--时间轮指针当前指向的槽
};

#endif