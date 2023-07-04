#include <iostream>
using namespace std;


class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() {}
};

class ElementA: public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementA(*this);
    }
};

class ElementB: public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementB(*this);
    }
};

class Visitor {
public:
    virtual void visitElementA(Element& element) = 0;
    virtual void visitElementB(Element& element) = 0;
    virtual ~Visitor() {}
};

// 将来需要增加的部分

class Visitor1: public Visitor {
    void visitElementA(Element& element) override {
        cout << "Visitor1 is processing ElementA" << endl;
    }
    void visitElementB(Element& element) override {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};

class Visitor2: public Visitor {
    void visitElementA(Element& element) override {
        cout << "Visitor2 is processing ElementA" << endl;
    }
    void visitElementB(Element& element) override {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};


int main() {
    Visitor2 visitor2;
    ElementA elementA;
    elementA.accept(visitor2); // double dispatch
}
