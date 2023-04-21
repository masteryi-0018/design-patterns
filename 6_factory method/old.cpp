#include <iostream>
using namespace std;

// 抽象基类
class ISplitter {
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

// 具体类型
class BinarySplitter: public ISplitter {
public:
    void split() {
        // ...
    }
};

class TxtSplitter: public ISplitter {

};

class PictureSplitter: public ISplitter {

};

class VideoSplitter: public ISplitter {

};


class MainForm {
public:
    void buttonClick() {
        // 没有绕开具体类
        ISplitter* splitter = new BinarySplitter();
        splitter->split();
    }
};