#include <iostream>
using namespace std;

// 枚举状态
enum NetworkState {
    Network_Open,
    Network_Close,
    Network_Connect,
    // 新增 Network_Wait 会遇到新增 if-else 的情况
};

// 根据状态处理对象
class NetworkProcessor {
    NetworkState state;
public:
    void Operation1() {
        if (state == Network_Open) {
            // ...
            state = Network_Close;
        } else if (state == Network_Close) {
            // ...
            state = Network_Connect;
        } else if (state == Network_Connect) {
            // ...
            state = Network_Open;
        }
    }

    void Operation2() {
        if (state == Network_Open) {
            // ...
            state = Network_Connect;
        } else if (state == Network_Close) {
            // ...
            state = Network_Open;
        } else if (state == Network_Connect) {
            // ...
            state = Network_Close;
        }
    }

    void Operation3() {
        // ...
    }

    // ...
};