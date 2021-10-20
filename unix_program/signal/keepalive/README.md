# 使用定时器升序链表实现keepalive
使用定时器升序链表实现sockeet keepalive机制,定时处理非活动连接

## lst_time
动态管理定时器链表
## keep_alive
定时器处理函数

## 部署
g++ main.cpp keep_alive.cpp lst_timer.cpp -o main