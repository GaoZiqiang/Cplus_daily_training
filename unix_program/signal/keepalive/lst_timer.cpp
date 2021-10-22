#include <stdio.h>
#include "lst_timer.h"

sort_timer_list::sort_timer_list() {
    head = nullptr;
    tail = nullptr;
}

sort_timer_list::~sort_timer_list() {
    util_timer* tmp = head;
    while(tmp) {
        head = tmp -> next;
        delete tmp;
        tmp = head;
    }
}

void sort_timer_list::add_timer(util_timer* timer) {
    // timer链表为空
    if(!timer)
    {
        return;
    }

    // 添加第一个timer
    if(!head) {
        head = tail = timer;
        return;
    }

    // 插入需按序插入，时间复杂度会较大--时间轮法的插入为无序链表插入，只需要插入表头即可，时间复杂度为O(1)
    // 升序--找第一个比自己大的--经排序后再插入链表--插入排序--时间复杂度为O(N^2)--最坏
    // 为什么不用while直接找到呢？
    if(timer -> expire < head -> expire) {
        timer -> next = head;
        head -> prev = timer;
        head = timer;
        return;
    }

    // 调用void add_timer(util_timer* timer, util_timer* lst_head);
    add_timer(timer, head);
}

void sort_timer_list::adjust_timer(util_timer* timer) {
    if(!timer) return;
    util_timer* tmp = timer -> next;
    if(!tmp || (timer -> expire < tmp -> expire)) return;
    if(timer == head) {
        head = head -> next;
        head -> prev = NULL;
        timer -> next = NULL;
        add_timer(timer, head);
    }
    else {
        timer -> prev -> next = timer -> next;
        timer -> next -> prev = timer -> prev;
        add_timer(timer, timer -> next);
    }
}

void sort_timer_list::del_timer(util_timer* timer) {
    if(!timer) return;
    if((timer == head) && (timer == tail)) {
        delete timer;
        head = NULL;
        tail = NULL;
        return;
    }
    if(timer == head) {
        head = head -> next;
        head -> prev = NULL;
        delete timer;
        return;
    }
    if(timer == tail) {
        tail = tail -> prev;
        tail -> next = NULL;
        delete timer;
        return;
    }
    // 双向链表的删除操作
    timer -> prev -> next = timer -> next;
    timer -> next -> prev = timer -> prev;
    delete timer;
}

// 检查定时器链表中是否有定时器到期
void sort_timer_list::tick(int epollfd) {
    // 没有客户端连接便return
    if(!head)
    {
        printf("没有客户端连接\n");
        return;
    }

    printf("timer tick\n");
    time_t cur = time(NULL);
    util_timer* tmp = head;// 升序链表--头结点的超时时长expire是最小的
    while(tmp) {
        // 判断超时--头结点没有超时便意味着后边的节点肯定也不会超时--所以只需要判断头结点即可
        // 没有超时
        if(cur < tmp -> expire)
        {
            printf("客户端 %d 连接没有超时\n", epollfd);
            break;
        }
        // 超时--从链表中删除
        printf("客户端 %d 连接超时,即将断开连接\n", epollfd);
        tmp -> cb_func(tmp -> user_data, epollfd);
        head = tmp -> next;
        if(head) head -> prev = NULL;
        delete tmp;
        tmp = head;
    }
}

void sort_timer_list::add_timer(util_timer *timer, util_timer *lst_head) {
    util_timer* prev = lst_head;
    util_timer* tmp = prev -> next;
    while(tmp) {
        if(timer -> expire < tmp -> expire) {
            prev -> next = timer;
            timer -> next = tmp;
            tmp -> prev = timer;
            timer -> prev = prev;
            break;
        }
        prev = tmp;
        tmp = tmp -> next;
    }
    if(!tmp) {
        prev -> next = timer;
        timer -> prev = prev;
        timer -> next = NULL;
        tail = timer;
    }
}