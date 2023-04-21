#include <iostream>
using namespace std;

// 库开发者负责主流程
class Library {
public:
    void Run() {
        step1();
        if (step2()) {
            step3();
        }
        for (int i = 0; i < 4; ++i) {
            step4();
        }
        step5();
    }
    virtual ~Library() {}
protected:
    void step1() {
        cout << "i am step 1" << endl;
    }
    void step3() {
        cout << "i am step 3" << endl;
    }
    void step5() {
        cout << "i am step 5" << endl;
    }
    virtual bool step2() = 0;
    virtual void step4() = 0;
};

class Application: public Library {
protected:
    bool step2() {
        cout << "i am step 2 from Application" << endl;
        return true;
    }
    void step4() {
        cout << "i am step 4 from Application" << endl;
    }
};

int main() {
    // 多态指针
    Library* lib = new Application();
    lib->Run();

    return 0;
}