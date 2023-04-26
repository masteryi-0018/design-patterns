#include <iostream>
using namespace std;

class Singleton {
// 构造函数声明私有，否则外部也可以构建
private:
    Singleton();
    Singleton(const Singleton &other);
public:
    static Singleton *getInstance();
    static Singleton *m_instance;
};

// 线程非安全版本
Singleton *Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

// 线程安全版本，但是锁的代价较高
Singleton *Singleton::getInstance() {
    Lock lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}

// 双检查锁，但是内存读取reorder不安全
Singleton *Singleton::getInstance() {
    if (m_instance == nullptr) {
        Lock lock;
        if (m_instance == nullptr) {
        m_instance = new Singleton();
        }
    }
    return m_instance;
}

// C++11，使用原子操作
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton *Singleton::getInstance() {
    // tmp不会被reorder
    Singleton *tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); // 获取内存fence

    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 释放内存fence
            m_instance.store(std::memory_order_relaxed);
        }
    }
    return tmp;
}