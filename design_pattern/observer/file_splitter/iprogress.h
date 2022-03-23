#ifndef CONTROL_BASE_H_
#define CONTROL_BASE_H_

class IProgress {
public:
    virtual void doProgress(int n) = 0;
    virtual ~IProgress() {}
};

#endif
