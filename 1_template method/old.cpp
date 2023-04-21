#include <iostream>
using namespace std;

class Library {
public:
    void step1() {
        cout << "i am step 1" << endl;
    }
    void step3() {
        cout << "i am step 3" << endl;
    }
    void step5() {
        cout << "i am step 5" << endl;
    }
};

// 应用程序开发者负责主流程
class Application {
public:
    bool step2() {
        cout << "i am step 2 from Application" << endl;
        return true;
    }
    void step4() {
        cout << "i am step 4 from Application" << endl;
    }
};

int main() {
    Library* lib = new Library();
    Application* app = new Application();

    lib->step1();
    if (app->step2()) {
        lib->step3();
    }
    for (int i = 0; i < 4; ++i) {
        app->step4();
    }
    lib->step5();

    return 0;
}