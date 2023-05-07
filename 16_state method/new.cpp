#include <iostream>
using namespace std;

// 状态抽象基类
class NetworkState {
public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState() {}
};

// 具体状态类
class OpenState: public NetworkState {
    static NetworkState* m_instance;
public:
    // 单例模式
    static NetworkState* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }

    void virtual Operation1() {
        // ...
        // 更改对象
        pNext = CloseState::getInstance();
    }
    void virtual Operation2() {
        // ...
        // 更改对象
        pNext = ConnectState::getInstance();
    }
    void virtual Operation3() {
        // ...
        // 更改对象
        pNext = OpenState::getInstance();
    }
};

class CloseState: public NetworkState {
    // ...
};

class ConnectState: public NetworkState {
    // ...
};

// 增加 `Network_Wait` 状态时，只需要增加子类即可

class NetworkProcessor {
    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState) {
        this->pState = pState;
    }

    void Operation1() {
        pState->Operation1();
        pState = pState->pNext;
    }
    void Operation2() {
        pState->Operation2();
        pState = pState->pNext;
    }

    void Operation3() {
        pState->Operation3();
        pState = pState->pNext;
    }
};