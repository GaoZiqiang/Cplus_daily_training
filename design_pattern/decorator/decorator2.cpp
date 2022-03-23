#include <iostream>

using namespace std;

// 业务操作
class Stream {
public:
    virtual char read(int number) = 0;
    virtual void seek(int position) = 0;
    virtual void write(char data) = 0;

    virtual ~Stream() {}
};

// 主体类
class FileStream : public Stream {
public:
    virtual char read(int number) override {
        // 读文件流
    }
    virtual void seek(int position) override {
        // 定位文件流
    }
    virtual void write(char data) override {
        // 写文件流
    }
};

class NetworkStream : public Stream {
public:
    virtual char read(int number) override {
        // 读网络流
    }
    virtual void seek(int position) override {
        // 定位网络流
    }
    virtual void write(char data) override {
        // 写网络流
    }
};

class MemoryStream : public Stream {
public:
    virtual char read(int number) override {
        // 读内存流
    }
    virtual void seek(int position) override {
        // 定位内存流
    }
    virtual void write(char data) override {
        // 写内存流
    }
};

// Decorator层
class DecoratorStream : public Stream {
protected:
    DecoratorStream(Stream* _stream) : stream(_stream) {}
    Stream* stream;
};

// 拓展操作
// 加密操作
class CryptoStream : public DecoratorStream {
public:
    // 注入Decorator
    CryptoStream(Stream* _stream) : DecoratorStream(_stream) {}
    // 组合替代继承
//    Stream* stream;// FileStream NetworkStream ... 运行时多态

public:
    virtual char read(int number) {// virtual虚函数来自基类Stream
        cout << "额外的加密操作\n";
        stream->read(number);
    }
    virtual void seek(int position) {
        cout << "额外的加密操作\n";
        stream->seek(position);
    }
    virtual void write(char data) {
        cout << "额外的加密操作\n";
        stream->write(data);
    }
};

// 缓存操作
class BufferedStream : public DecoratorStream {
public:
    // 注入Decorator
    BufferedStream(Stream* _stream) : DecoratorStream(_stream) {}
    // 组合替代继承
//    Stream* stream;// FileStream NetworkStream ... 运行时多态

public:
    virtual char read(int number) {// virtual虚函数来自基类Stream
        cout << "额外的buffer操作\n";
        stream->read(number);
    }
    virtual void seek(int position) {
        cout << "额外的buffer操作\n";
        stream->seek(position);
    }
    virtual void write(char data) {
        cout << "额外的buffer操作\n";
        stream->write(data);
    }
};

int main() {
    // 运行时装配？
    FileStream* fs = new FileStream();
    CryptoStream* cs = new CryptoStream(fs);
    BufferedStream* bs = new BufferedStream(fs);
    cs->read(1);
    bs->read(1);
}