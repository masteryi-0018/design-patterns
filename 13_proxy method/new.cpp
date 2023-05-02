#include <iostream>
using namespace std;

// 接口
class ISubject {
public:
    // ...
    virtual void process() = 0;
};

// 代理
class SubjectProxy: public ISubject {
    
public:
    // 完成RealSubject的间接访问（将RealSubject对象放入等）
    virtual void process() {

    }
};

// 客户端
class ClientAPP {
    ISubject *subject;
public:
    ClientAPP() {
        subject = new SubjectProxy(); // 建议通过工厂模式等设计模式完成
    }
    void DoTask() {
        // ...
        subject->process();

        // ...
    }
};