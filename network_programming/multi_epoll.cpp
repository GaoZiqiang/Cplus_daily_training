#include <netinet/in.h>
#include <iostream>
#include <sys/epoll.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>

#define WORKER_THREAD 4
#define PORT 9999
#define EVENT_NUM 1024

//创建socket，并返回fd
int createSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd < 0) {
        std::cout << "create socket error" << std::endl;
        return 0;
    }

    sockaddr_in sockAddr{};
    sockAddr.sin_port = htons(PORT);
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = htons(INADDR_ANY);

    if (bind(fd, (sockaddr *) &sockAddr, sizeof(sockAddr)) < 0) {
        std::cout << "bind socket error, port:" << PORT << std::endl;
        return 0;
    }

    if (listen(fd, 100) < 0) {
        std::cout << "listen port error" << std::endl;
        return 0;
    }
    return fd;
}

void Worker2(int socketFd, int k) {
    std::cout << " Worker" << k << " run " << std::endl;

    int eFd = epoll_create(1);
    if (eFd < 0) {
        std::cout << "create epoll fail";
        return;
    }
    epoll_event epev_{};
    epev_.events = EPOLLIN;
    epev_.data.fd = socketFd;
    epoll_ctl(eFd, EPOLL_CTL_ADD, socketFd, &epev_);
    epoll_event events[EVENT_NUM];

    while (true) {
        int eNum = epoll_wait(eFd, events, EVENT_NUM, -1);
        if (eNum == -1) {
            std::cout << "epoll error";
            return;
        }
        //一定要加上这句,防止事件被瞬间处理,导致看不到结果
        std::this_thread::sleep_for((std::chrono::seconds (1)));
        std::cout << "worker" << k << " in " << std::endl;
        for (int i = 0; i < eNum; ++i) {
            if (events[i].data.fd == socketFd) {
                int tfd = 0;
                sockaddr_in cli_addr{};
                socklen_t length = sizeof(cli_addr);
                tfd = accept(socketFd, (sockaddr *) &cli_addr, &length);
                if (tfd <= 0) {
                    std::cout << "accept error" << std::endl;
                } else {
                    std::cout << "worker" << k << " accept " << std::endl;
                }
            } else {
                //处理正常的socket读写事件,这里可以忽略,不是这次关注的点
            }
        }
    }
}

int main() {
    std::mutex mutex;
    std::unique_lock<std::mutex> lck(mutex);
    std::condition_variable cv;
    int fd = createSocket();
    //第二种,多个线程使用epoll多路复用,accept同一个socket
    for (int i = 0; i < WORKER_THREAD; ++i) {
        std::thread th(&Worker2, fd, i + 1);
        th.detach();
    }
    sleep(1000);
}