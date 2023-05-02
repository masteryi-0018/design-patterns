#include <iostream>
using namespace std;

// 接口
class ISubject {
public:
    // ...
    virtual void process() = 0;
};

// 具体类
class RealSubject: public ISubject {
public:
    // ...
    virtual void process() {

    }
};

// 客户端
class ClientAPP {
    ISubject *subject;
public:
    ClientAPP() {
        subject = new RealSubject(); // 建议通过工厂模式等设计模式完成
    }
    void DoTask() {
        // ...
        subject->process();

        // ...
    }
};