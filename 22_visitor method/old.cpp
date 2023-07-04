#include <iostream>
using namespace std;


class Element {
public:
    virtual void Func1() = 0;
    virtual void Func2(int data) = 0;
    virtual ~Element() {}
    
    // 如果需要添加新的操作
    virtual void Func3() = 0;
    virtual void Func4() = 0;
    // Func5
};

class ElementA: public Element {
public:
    void Func1() override {
        // ...
    }
    void Func2(int data) override {
        // ...
    }
};

class ElementB: public Element {
public:
    void Func1() override {
        // ***
    }
    void Func2(int data) override {
        // ***
    }
};
