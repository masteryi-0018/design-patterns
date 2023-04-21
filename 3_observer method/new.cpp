#include <iostream>
#include <vector>
using namespace std;

class IProgress {
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {}
};

class FileSplitter {
private:
    string m_filePath;
    int m_fileNumber;
    // 抽象通知机制
    IProgress* m_iprogress;
    // 多个观察者使用容器保存
    vector<IProgress*> m_iprogressVector;

public:
    FileSplitter(string& filePath, int fileNumber, IProgress* iprogress):
        m_filePath(filePath), 
        m_fileNumber(fileNumber), 
        m_iprogress(iprogress) {
    }

    void split() {
        for (int i = 0; i < m_fileNumber; ++i) {
            m_iprogress->DoProgress(i);
            // 多个观察者使用容器保存
        }
    }

    // 多个观察者
    void add() {}

    void remove() {}
};

// 主逻辑
class Form {};

class TextBox {
public:
    string getText() {
        return "";
    }
};

class ProgressBar {
public:
    void setValue() {}
};

class MainForm: public Form, public IProgress {
private:
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;

public:
    void buttonClick() {
        string filePath = txtFilePath->getText();
        int fileNumber = atoi(txtFileNumber->getText().c_str());

        // this比较重要
        FileSplitter* splitter = new FileSplitter(filePath, fileNumber, this);

        splitter->split();
    }

    // 不论有多少个观察者，都可以实现自己的通知机制
    virtual void Doprogress(float value) {
        progressBar->setValue();
    }
};