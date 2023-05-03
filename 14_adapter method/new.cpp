#include <iostream>
using namespace std;

// 目标接口
class ITarget {
public:
    virtual void process() = 0;
};

// 遗留接口
class IAdaptee {
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

// 旧对象
class OldClass: public IAdaptee {
public:
    // 具体实现
    virtual void foo(int data) {

    }
    virtual int bar() {

    }
};

// 实现适配器
class Adapter: public ITarget {
private:
    IAdaptee* pAdaptee;
public:
    Adapter(IAdaptee* pAdaptee) {
        this->pAdaptee = pAdaptee;
    }
    // 例如
    virtual void process() {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

int main() {
    // 旧的对象
    IAdaptee* pAdaptee = new OldClass();

    // 塞到适配器中，满足新的接口
    ITarget* pAdapter = new Adapter(pAdaptee);
    pAdapter->process();
}