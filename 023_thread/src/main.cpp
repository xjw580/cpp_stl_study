/**************************************************************************

Author:肖嘉威

Version:1.0.0

Date:2025/5/14 10:05

Description:https://www.runoob.com/cplusplus/cpp-signal-handling.html

**************************************************************************/

import std;

using namespace std;

// 一个简单的函数，作为线程的入口函数
void foo(int Z) {
    for (int i = 0; i < Z; i++) {
        cout << "线程使用函数指针作为可调用参数\n";
    }
}

// 可调用对象的类定义
class ThreadObj {
public:
    void operator()(int x) const {
        for (int i = 0; i < x; i++) {
            cout << "线程使用函数对象作为可调用参数\n";
        }
    }
};

void unique_ptr_demo() {
    cout << "线程 1 、2 、3 独立运行" << endl;

    // 使用函数指针创建线程
    thread th1(foo, 3);

    // 使用函数对象创建线程
    thread th2(ThreadObj(), 3);

    // 使用 Lambda 表达式创建线程
    thread th3([](int x) {
        for (int i = 0; i < x; i++) {
            cout << "线程使用 lambda 表达式作为可调用参数\n";
        }
    }, 3);

    // 等待所有线程完成
    th1.join(); // 等待线程 th1 完成
    th2.join(); // 等待线程 th2 完成
    th3.join(); // 等待线程 th3 完成
}

void shared_ptr_demo() {
    static std::mutex mutex;
    std::lock_guard lock(mutex);

    std::cout << "demo2" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void demo3() {
    static std::mutex mutex;
    std::unique_lock lock(mutex);
    std::cout << "demo3" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    lock.unlock();
}

class TimedLatch {
public:
    explicit TimedLatch(int count) : count_(count) {
    }

    void count_down() {
        std::unique_lock lock(mtx_);
        if (--count_ <= 0) {
            cv_.notify_all();
        }
    }

    bool wait_for(std::chrono::milliseconds timeout) {
        std::unique_lock lock(mtx_);
        return cv_.wait_for(lock, timeout, [&]() { return count_ <= 0; });
    }

private:
    std::mutex mtx_;
    std::condition_variable cv_;
    int count_;
};

void demo4() {
    auto tl = std::make_shared<TimedLatch>(1); // 使用智能指针管理
    std::thread t1([tl] {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        tl->count_down(); // 安全：tl 生命周期延长到线程结束
    });
    t1.detach();

    if (tl->wait_for(std::chrono::seconds(2))) {
        std::cout << "唤醒成功\n";
    } else {
        std::cout << "等待超时\n";
    }
}

void demo5() {
    std::queue<int> production;
    std::mutex mtx;
    std::condition_variable cv;
    bool ready = false; // 是否有产品可供消费
    bool done = false; // 生产结束

    std::thread producer(
        [&] {
            for (int i = 1; i < 10; ++i) {
                // 模拟实际生产过程
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                std::cout << "producing " << i << std::endl;

                std::unique_lock lock(mtx);
                production.push(i);

                // 有产品可以消费了
                ready = true;
                cv.notify_one();
            }
            // 生产结束了
            done = true;
        }
    );

    std::thread consumer(
        [&] {
            std::unique_lock lock(mtx);
            // 如果生成没有结束或者队列中还有产品没有消费，则继续消费，否则结束消费
            while (!done || !production.empty()) {
                // 防止误唤醒
                cv.wait(lock, [&] { return ready; });

                while (!production.empty()) {
                    // 模拟消费过程
                    std::cout << "consuming " << production.front() << std::endl;
                    production.pop();
                }

                // 没有产品了
                ready = false;
            }
        }
    );

    producer.join();
    consumer.join();
}

void demo6() {
    std::atomic value = 0;
    std::thread t1([&] {
        for (int i = 0; i < 10000; ++i) {
            value.fetch_add(1, std::memory_order_relaxed);
        }
    });
    std::thread t2([&] {
        for (int i = 0; i < 10000; ++i) {
            value.fetch_add(1, std::memory_order_relaxed);
        }
    });
    t1.join();
    t2.join();
    cout << "value: " << value.load() << endl;
}

thread_local int threadData = 0;

void threadFunction() {
    static std::mutex mtx;
    threadData = 42; // 每个线程都有自己的threadData副本
    std::lock_guard lock(mtx);
    std::cout << "Thread data: " << &threadData << std::endl;
}

void demo7() {
    for (int i = 0; i < 10; ++i) {
        std::thread t(threadFunction);
        t.detach();
    }
}

// 线程间通信
void demo8() {
    auto p = make_shared<std::promise<int> >();
    std::thread t([p] {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        p->set_value(10); // 设置值，触发 future
    });
    t.detach();

    std::future<int> f = p->get_future();
    // if (const future_status future_status = f.wait_for(std::chrono::seconds(2));
    if (const future_status future_status = f.wait_until(
            std::chrono::system_clock::now() + std::chrono::seconds(2));
        future_status == std::future_status::ready) {
        cout << "res:" << f.get() << endl;
    } else {
        cout << "timeout" << endl;
    }
}

void demo9() {
    future<int> future = std::async(std::launch::async, [](const int x, const int y)-> int {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return x + y;
    }, 10, 20);
    if (auto future_status = future.wait_for(std::chrono::seconds(2)); future_status == std::future_status::ready) {
        cout << "res: " << future.get() << endl;
    } else {
        cout << "timeout" << endl;
    }
}

void main() {
    // demo1();

    // for (int i = 0; i < 3; ++i) {
    //     std::thread t(demo2);
    //     t.detach();
    // }

    // for (int i = 0; i < 3; ++i) {
    //     std::thread t(demo3);
    //     t.detach();
    // }

    // demo4();

    // demo5();

    // demo6();

    // demo7();

    // demo8();

    demo9();
    cout << "over" << endl;
    std::cout.flush();
    std::cin.get();
}
