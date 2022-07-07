class Base {
public:
    virtual Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    virtual Derived() {}
    virtual ~Derived() {}
};

int main() {
    Derived d;
    return 0;
}