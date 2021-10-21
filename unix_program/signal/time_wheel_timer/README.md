# 使用定时器时间轮法实现keepalive
使用定时器时间轮法实现sockeet keepalive机制,定时处理非活动连接

## time_wheel_timer
动态管理定时器时间轮
## use_timer
定时器处理函数

## 部署
g++ use_timer.cpp -o main
