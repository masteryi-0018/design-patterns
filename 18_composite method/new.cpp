#include <iostream>
using namespace std;

// 抽象基类
class Component {
public:
    virtual void process() = 0;
    virtual ~Component() {}
};

// 子节点
class Composite: public Component {
    string name;
    list<Component*> elements;
public:
    Composite(const string& s): name(s) {}
    void add(Component* element) {
        elements.push_back(element);
    }
    void remove(Component* element) {
        elements.remove(element);
    }

    void process() {
        // 处理当前节点
        // 处理子节点
        for (auto& e: elements) {
            e->process(); // 虚函数调用，多态
        }
    }
};

// 叶子节点
class Leaf: public Component {
    string name;
public:
    Leaf(string s): name(s) {}
    void process() {
        // 处理当前节点，不需要循环
    }
};

void Invoke(Component& c) {
    c.process();
}


void main() {
    Composite root("root");
    Composite treeNode1("treeNode1");
    Composite treeNode2("treeNode2");
    Composite treeNode3("treeNode3");
    Composite treeNode4("treeNode4");
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");

    // 建树
    root.add(&treeNode1);
    treeNode1.add(&treeNode2);
    treeNode2.add(&leaf1);

    root.add(&treeNode3);
    treeNode3.add(&treeNode4);
    treeNode4.add(&leaf2);

    // 统一处理
    Invoke(root);
    Invoke(leaf2);
    Invoke(treeNode3);
}