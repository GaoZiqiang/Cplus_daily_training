#include <iostream>
#include "iprogress.h"

using std::cout;

class ProgressBar : public IProgress {
public:
    virtual void doProgress(int n) override {
        cout << "ProgressBar::doProgress, value = " << n << "\n";
    }
};

class ProgressConsole : public IProgress {
public:
    virtual void doProgress(int n) override {
        cout << "ProgressConsole::doProgress, value = " << n << "\n";
    }
};

class ProgressPercent : public IProgress {
public:
    virtual void doProgress(int n) override {
        cout << "ProgressPercent::doProgress, value = " << n << "\n";
    }
};