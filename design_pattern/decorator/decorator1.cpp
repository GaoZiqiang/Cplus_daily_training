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

// 拓展操作
class CryptoFileStream : public FileStream {
public:
    virtual char read(int number) {
        cout << "额外的加密操作\n";
        FileStream::read(number);// 读文件流
    }
    virtual void seek(int position) {
        cout << "额外的加密操作\n";
        FileStream::seek(position);// 定位文件流
    }
    virtual void write(char data) {
        cout << "额外的加密操作\n";
        FileStream::write(data);// 写文件流
    }
};

class CryptoNetworkStream : public NetworkStream {
public:
    virtual char read(int number) {
        cout << "额外的加密操作\n";
        NetworkStream::read(number);// 读网络流
    }
    virtual void seek(int position) {
        cout << "额外的加密操作\n";
        NetworkStream::seek(position);// 定位网络流
    }
    virtual void write(char data) {
        cout << "额外的加密操作\n";
        NetworkStream::write(data);// 写网络流
    }
};

class CryptoMemoryStream : public MemoryStream {
public:
    virtual char read(int number) {
        cout << "额外的加密操作\n";
        MemoryStream::read(number);// 读内存流
    }
    virtual void seek(int position) {
        cout << "额外的加密操作\n";
        MemoryStream::seek(position);// 定位内存流
    }
    virtual void write(char data) {
        cout << "额外的加密操作\n";
        MemoryStream::write(data);// 写内存流
    }
};

// 缓存操作
class BufferedFileStream : public FileStream {
public:
    virtual char read(int number) {
        cout << "额外的buffer操作\n";
        FileStream::read(number);// 读文件流
    }
    virtual void seek(int position) {
        cout << "额外的buffer操作\n";
        FileStream::seek(position);// 定位文件流
    }
    virtual void write(char data) {
        cout << "额外的buffer操作\n";
        FileStream::write(data);// 写文件流
    }
};

class BufferedNetworkStream : public NetworkStream {
public:
    virtual char read(int number) {
        cout << "额外的buffer操作\n";
        NetworkStream::read(number);// 读文件流
    }
    virtual void seek(int position) {
        cout << "额外的buffer操作\n";
        NetworkStream::seek(position);// 定位文件流
    }
    virtual void write(char data) {
        cout << "额外的buffer操作\n";
        NetworkStream::write(data);// 写文件流
    }
};

class BufferedMemoryStream : public MemoryStream {
public:
    virtual char read(int number) {
        cout << "额外的buffer操作\n";
        MemoryStream::read(number);// 读文件流
    }
    virtual void seek(int position) {
        cout << "额外的buffer操作\n";
        MemoryStream::seek(position);// 定位文件流
    }
    virtual void write(char data) {
        cout << "额外的buffer操作\n";
        MemoryStream::write(data);// 写文件流
    }
};


int main() {
    // 编译时装配
    CryptoFileStream* cfs = new CryptoFileStream();
    cfs->read(1);
    BufferedFileStream* bfs = new BufferedFileStream();
    bfs->read(1);
}