#include <iostream>
using namespace std;

class Messager{
protected:
    MessagerImp* messagerImp;
public:
    Messager(MessagerImp* mImp) {
        // 初始化字段messagerImp
        messagerImp = mImp;
    }
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string massage) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual ~Messager() {}
};

class MessagerImp{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

// 平台实现
class PCMessagerImp: public MessagerImp{
public:
    virtual void PlaySound() {
        // ...
    }
    virtual void DrawShape() {
        // ...
    }
    virtual void WriteText() {
        // ...
    }
    virtual void Connect() {
        // ...
    }
};

class MobileMessagerImp: public MessagerImp{
public:
    virtual void PlaySound() {
        // ...
    }
    virtual void DrawShape() {
        // ...
    }
    virtual void WriteText() {
        // ...
    }
    virtual void Connect() {
        // ...
    }
};

// 业务抽象
class MessagerLite: public Messager{
    // 重写构造函数，new的对象不同
public:
    virtual void Login(string username, string password) {
        messagerImp->Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        messagerImp->WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        messagerImp->DrawShape();
        // ...
    }
};

class MessagerPerfect: public Messager{
public:
    virtual void Login(string username, string password) {
        messagerImp->PlaySound();
        // ...
        messagerImp->Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        messagerImp->PlaySound();
        // ...
        messagerImp->WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        messagerImp->PlaySound();
        // ...
        messagerImp->DrawShape();
        // ...
    }
};

void Process() {
    // 运行时装配
    MessagerImp* mImp = new PCMessagerImp();
    Messager* m = new Messager(mImp);
}