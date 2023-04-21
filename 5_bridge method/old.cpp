#include <iostream>
using namespace std;

class Messager{
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string massage) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~Messager() {}
};

// 平台实现
class PCMessagerBase: public Messager{
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

class MobileMessagerBase: public Messager{
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
class PCMessagerLite: public PCMessagerBase{
public:
    virtual void Login(string username, string password) {
        PCMessagerBase::Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        PCMessagerBase::WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        PCMessagerBase::DrawShape();
        // ...
    }
};

class PCMessagerPerfect: public PCMessagerBase{
public:
    virtual void Login(string username, string password) {
        PCMessagerBase::PlaySound();
        // ...
        PCMessagerBase::Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        PCMessagerBase::PlaySound();
        // ...
        PCMessagerBase::WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        PCMessagerBase::PlaySound();
        // ...
        PCMessagerBase::DrawShape();
        // ...
    }
};

class MobileMessagerLite: public MobileMessagerBase{
public:
    virtual void Login(string username, string password) {
        MobileMessagerBase::Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        MobileMessagerBase::WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        MobileMessagerBase::DrawShape();
        // ...
    }
};

class MobileMessagerPerfect: public MobileMessagerBase{
public:
    virtual void Login(string username, string password) {
        MobileMessagerBase::PlaySound();
        // ...
        MobileMessagerBase::Connect();
        // ...
    }
    virtual void SendMessage(string massage) {
        MobileMessagerBase::PlaySound();
        // ...
        MobileMessagerBase::WriteText();
        // ...
    }
    virtual void SendPicture(string massage) {
        MobileMessagerBase::PlaySound();
        // ...
        MobileMessagerBase::DrawShape();
        // ...
    }
};

void Process() {
    // 编译时装配
    Messager* m = new MobileMessagerPerfect();
}