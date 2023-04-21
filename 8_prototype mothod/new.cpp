#include <iostream>
using namespace std;

// 基类
class ISplitter {
public:
    virtual void split() = 0;
    virtual ISplitter* clone() = 0; // 通过可克隆自己来实现

    virtual ~ISplitter() {}
};

// 类型
class BinarySplitter: public ISplitter {
public:
    void split() {
        // ...
    }
    virtual ISplitter* clone() {
        return new BinarySplitter(*this);
    }
};

class TxtSplitter: public ISplitter {
    virtual ISplitter* clone() {
        return new TxtSplitter(*this);
    }
};

class PictureSplitter: public ISplitter {
    virtual ISplitter* clone() {
        return new PictureSplitter(*this);
    }
};

class VideoSplitter: public ISplitter {
    virtual ISplitter* clone() {
        return new VideoSplitter(*this);
    }
};


// MainForm不再依赖具体类
class MainForm {
private:
    ISplitter* prototype; // 只用来克隆
public:
    MainForm(ISplitter* prototype) {
        this->prototype = prototype;
    }
    void buttonClick() {
        // 通过克隆原型，得到新对象
        ISplitter* splitter = prototype->clone(); 
        splitter->split();
    }
};