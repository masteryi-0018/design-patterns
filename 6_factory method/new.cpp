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

// 工厂基类
class SplitterFactory {
public:
    virtual ISplitter* CreateSpitter() = 0;
    virtual ~SplitterFactory() {}
};

// 具体工厂
class BinarySplitterFactory: public SplitterFactory {
public:
    virtual ISplitter* CreateSpitter() {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory: public SplitterFactory {
public:
    virtual ISplitter* CreateSpitter() {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory: public SplitterFactory {
public:
    virtual ISplitter* CreateSpitter() {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory: public SplitterFactory {
public:
    virtual ISplitter* CreateSpitter() {
        return new VideoSplitter();
    }
};

// MainForm不再依赖具体类
class MainForm {
private:
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* factory) {
        this->factory = factory;
    }
    void buttonClick() {
        // 多态new
        ISplitter* splitter = factory->CreateSpitter();
        splitter->split();
    }
};