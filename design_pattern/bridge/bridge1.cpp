// 使用Bridge模式优化之前的代码

// 业务操作
class Messager {
public:
    virtual void login() = 0;
    virtual void sendMessage() = 0;
    virtual void sendPicture() = 0;

    virtual void playSound() = 0;
    virtual void drawShape() = 0;
    virtual void writeText() = 0;
    virtual void connect() = 0;

    virtual ~Messager() {};
};

// 主体类
class PCMessagerBase : public Messager {
    // login sendMessage sendPicture这三个虚函数没有实现
public:
    virtual void playSound() {
        // ***********
    }
    virtual void drawShape() {
        // ***********
    }
    virtual void writeText() {
        // ***********
    }
    virtual void connect() {
        // ***********
    }
};

class MobileMessagerBase : public Messager {
    // login sendMessage sendPicture这三个虚函数没有实现
public:
    virtual void playSound() {
        // ===========
    }
    virtual void drawShape() {
        // ===========
    }
    virtual void writeText() {
        // ===========
    }
    virtual void connect() {
        // ===========
    }
};

// 业务拓展
class PCMessagerLite : public PCMessagerBase {
public:
    virtual void login() {
        PCMessagerBase::connect();
    }
    virtual void sendMessage() {
        PCMessagerBase::writeText();
    }
    virtual void sendPicture() {
        PCMessagerBase::drawShape();
    }

};

class MobileMessagerLite : public MobileMessagerBase {
public:
    virtual void login() {
        MobileMessagerBase::connect();
    }
    virtual void sendMessage() {
        MobileMessagerBase::writeText();
    }
    virtual void sendPicture() {
        MobileMessagerBase::drawShape();
    }
};

class PCMessagerPerfect : public PCMessagerBase {
public:
    virtual void login() {
        PCMessagerBase::playSound();
        PCMessagerBase::connect();
    }
    virtual void sendMessage() {
        PCMessagerBase::playSound();
        PCMessagerBase::writeText();
    }
    virtual void sendPicture() {
        PCMessagerBase::playSound();
        PCMessagerBase::drawShape();
    }
};

class MobileMessagerPerfect : public MobileMessagerBase {
public:
    virtual void login() {
        MobileMessagerBase::playSound();
        MobileMessagerBase::connect();
    }
    virtual void sendMessage() {
        MobileMessagerBase::playSound();
        MobileMessagerBase::writeText();
    }
    virtual void sendPicture() {
        MobileMessagerBase::playSound();
        MobileMessagerBase::drawShape();
    }
};

int main() {
    Messager* messager = new MobileMessagerLite();
}