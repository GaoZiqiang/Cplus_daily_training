// 使用Bridge桥模式优化后的代码
// 业务操作
class MessagerImp;
class Messager {
public:
    Messager(MessagerImp* _messagerImp) : messagerImp(_messagerImp) {}
    MessagerImp* messagerImp;// 将decorator提到这里
public:
    virtual void login() = 0;
    virtual void sendMessage() = 0;
    virtual void sendPicture() = 0;

    virtual ~Messager() {};
};

// 不同类型的业务分离
class MessagerImp {
public:
    virtual void playSound() = 0;
    virtual void drawShape() = 0;
    virtual void writeText() = 0;
    virtual void connect() = 0;

    virtual ~MessagerImp() {};
};

// 主体类
class PCMessagerBase : public MessagerImp {
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

class MobileMessagerBase : public MessagerImp {
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
class MessagerLite : public Messager {
public:
    MessagerLite(MessagerImp* _messagerImp) : Messager(_messagerImp) {}
//    MessagerImp* messagerImp;// 提到Messager类中
public:
    virtual void login() {
        messagerImp->connect();
    }
    virtual void sendMessage() {
        messagerImp->writeText();
    }
    virtual void sendPicture() {
        messagerImp->drawShape();
    }

};

class MessagerPerfect : public Messager {
public:
    MessagerPerfect(MessagerImp* _messagerImp) : Messager(_messagerImp) {}
//    MessagerImp* messagerImp;// 提到Messager类中
public:
    virtual void login() {
        messagerImp->playSound();
        messagerImp->connect();
    }
    virtual void sendMessage() {
        messagerImp->playSound();
        messagerImp->writeText();
    }
    virtual void sendPicture() {
        messagerImp->playSound();
        messagerImp->drawShape();
    }
};

int main() {
//    Messager* messager = new MobileMessagerLite();
    Messager* messager = new MessagerLite(new PCMessagerBase());
    Messager* messager2 = new MessagerPerfect(new MobileMessagerBase());
}