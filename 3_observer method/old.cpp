#include <iostream>
using namespace std;

class FileSplitter {
private:
    string m_filePath;
    int m_fileNumber;
    ProgressBar* m_progressBar;

public:
    FileSplitter(string& filePath, int fileNumber, ProgressBar* progressBar):
        m_filePath(filePath), 
        m_fileNumber(fileNumber), 
        m_progressBar(progressBar) {
    }

    void split() {
        for (int i = 0; i < m_fileNumber; ++i) {
            m_progressBar->setValue();
        }
    }
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

class MainForm: Form {
private:
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;

public:
    void buttonClick() {
        string filePath = txtFilePath->getText();
        int fileNumber = atoi(txtFileNumber->getText().c_str());

        FileSplitter* splitter = new FileSplitter(filePath, fileNumber, progressBar);
        splitter->split();
    }
};