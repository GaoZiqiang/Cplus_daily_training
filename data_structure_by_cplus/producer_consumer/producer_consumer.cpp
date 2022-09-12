// 生产者消费者模式
// 无界缓冲区

// 消费者
consumer() {
    while (queue.empty()) {
        notEmpty.wait();
    }

    lock(mutex);
    queue.pop();
    unlock(mutex);

    notFull.signal();
}

// 生产者
producer() {
    lock(mutex);
    queue.push(x);
    unlock(mutex);

    notEmpty.signal();
}

// 有界缓冲区
// 生产者
producer() {
    while (queue.full()) {
        notFull.wait();
    }

    lock(mutex);
    queue.push(x);
    unlock(mutex);

    notEmpty.signal();
}

// 消费者
consumer() {
    while (queue.empty()) {
        notEmpty.wait();
    }

    lock(mutex);
    queue.pop();
    unlock(mutex);

    notFull.signal();
}


void put(const T& x)
{
    MutexLockGuard lock(mutex_);
    // 判断
    while (queue_.full())
    {
        notFull_.wait();// 等待队列不满
    }
    assert(!queue_.full());
    // 生产产品
    queue_.push_back(x);
    notEmpty_.notify();// notEmpty.signal()
}