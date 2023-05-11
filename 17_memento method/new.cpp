#include <iostream>
using namespace std;

class Memento {
    string state;
public:
    Memento(const string& s): state(s) {

    }
    string getState() const {
        return state;
    }
    void setState(const string& s) {
        state = s;
    }
};

class Originator {
    string state;
public:
    Originator() {

    }
    Memento createMemento() {
        Memento m(state);
        return m;
    }
    void setMemento(const Memento& m) {
        state = m.getState();
    }
};

int main() {
    // 创建原发器
    Originator originator;

    // 捕获对象状态，保存至备忘录
    Memento mem = originator.createMemento();

    // 从备忘录恢复对象
    originator.setMemento(mem);
}