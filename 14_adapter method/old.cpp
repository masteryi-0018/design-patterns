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

int main() {
    // 旧的对象
    IAdaptee* pAdaptee = new OldClass();

    // 无法直接调用process方法
}