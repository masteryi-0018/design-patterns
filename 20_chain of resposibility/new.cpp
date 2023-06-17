#include <iostream>
using namespace std;

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3,
};

class Request {
    string description;
    RequestType reqType;
public:
    Request(const string& desc, RequestType type): description(desc), reqType(type) {

    }
    RequestType getReqType() const {
        return reqType;
    }
    const string& getDescription() const {
        return description;
    }
};

// 父类
class ChainHandler {
    ChainHandler* nextChain;
    void sendRequestToNextHandler(const Request& req) {
        if (nextChain != nullptr) {
            nextChain->handle(req);
        }
    }
protected:
    virtual bool canHandleRequest(const Request& req) = 0;
    virtual void processRequest(const Request& req) = 0;
public:
    ChainHandler() {
        nextChain = nullptr;
    }
    void sentNextChain(ChainHandler* next) {
        nextChain = next;
    }
    void handle(const Request& req) {
        if (canHandleRequest(req)) {
            processRequest(req);
        }
        else {
            sendRequestToNextHandler(req);
        }
    }
};

// 子类
class Handler1: public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) {
        return req.getReqType() == RequestType::REQ_HANDLER1;
    }
    void processRequest(const Request& req) override {
        cout << "Handler1 is handle request: " << req.getDescription() << endl;
    }
};

class Handler2: public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Request& req) override {
        cout << "Handler2 is handle request: " << req.getDescription() << endl;
    }
};

class Handler3: public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Request& req) override {
        cout << "Handler3 is handle request: " << req.getDescription() << endl;
    }
};

int main() {
    // 构建链表
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.sentNextChain(&h2);
    h2.sentNextChain(&h3);

    // 从链表头开始处理，直到遇到可以处理的对象
    Request req("process task ...", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}