#include <iostream>
using namespace std;

class TaxStrategy {
public:
    virtual void calculate() = 0;
    virtual ~TaxStrategy() {}
};

class CNTax: public TaxStrategy {
public:
    virtual void calculate() {
        cout << "i am CN_tax" << endl;
    }
};

class USTax: public TaxStrategy {
public:
    virtual void calculate() {
        cout << "i am US_tax" << endl;
    }
};

class DETax: public TaxStrategy {
public:
    virtual void calculate() {
        cout << "i am DE_tax" << endl;
    }
};

class SalesOrder {
private:
    // 多态指针
    TaxStrategy* strategy;
public:
    // 使用工厂方法改变strategy指针（挖坑，后面填）
    SalesOrder() {}
    ~SalesOrder() {}
    void calculate() {
        // 多态调用
        strategy->calculate();
    }
};

int main() {
    SalesOrder* order = new SalesOrder();
    order->calculate();

    return 0;
}