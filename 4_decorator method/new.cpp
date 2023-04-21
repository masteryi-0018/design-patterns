#include <iostream>
using namespace std;

// 业务操作
class Stream{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream: public Stream{
public:
    virtual char Read(int number) {
        // 读文件流
    }
    virtual void Seek(int position) {
        // 定位文件流
    }
    virtual void Write(char data) {
        // 写文件流
    }
};

class NetworkStream: public Stream{
public:
    virtual char Read(int number) {
        // 读网络流
    }
    virtual void Seek(int position) {
        // 定位网络流
    }
    virtual void Write(char data) {
        // 写网络流
    }
};

class MemoryStream: public Stream{
public:
    virtual char Read(int number) {
        // 读内存流
    }
    virtual void Seek(int position) {
        // 定位内存流
    }
    virtual void Write(char data) {
        // 写内存流
    }
};

// 扩展操作
class CryptoStream: public Stream{ // 定义了接口规范
    // 未来（运行时）变成new FileStream()、new NetworkStream()、new MemoryStream()
    Stream* stream;
public:
    // 构造函数
    CryptoStream(Stream* stm): stream(stm) {}

    virtual char Read(int number) {
        // 额外加密操作
        stream->Read(number); // 读xx流
    }
    virtual void Seek(int position) {
        // 额外加密操作
        stream->Seek(position); // 定位xx流
    }
    virtual void Write(char data) {
        // 额外加密操作
        stream->Write(data); // 写xx流
    }
};

// 其他需求
class BufferedStream: public Stream{
    Stream* stream;
public:
    // 构造函数
    BufferedStream(Stream* stm): stream(stm) {}
    
    virtual char Read(int number) {
        // 额外缓存操作
        stream->Read(number); // 读xx流
    }
    virtual void Seek(int position) {
        // 额外缓存操作
        stream->Seek(position); // 定位xx流
    }
    virtual void Write(char data) {
        // 额外缓存操作
        stream->Write(data); // 写xx流
    }
};

// process
void Process(){
    // 运行时通过组合装配
    FileStream* fs1 = new FileStream();
    CryptoStream* fs2 = new CryptoStream(fs1);
    BufferedStream* fs3 = new BufferedStream(fs1);
    // 既加密又缓存
    BufferedStream* fs4 = new BufferedStream(fs2);
}