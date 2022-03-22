#include <string>
#include "file_splitter.h"

using namespace std;

class Form {
public:
    char* m_txtFilePath;
    int m_txtFileNumber;
public:
    Form(char* txtFilePath, int txtFileNumber) : m_txtFilePath(txtFilePath), m_txtFileNumber(txtFileNumber) {}
    virtual void buttonClick() = 0;
    virtual ~Form() {}
};

class MainForm : public Form {
public:
    MainForm(char* txtFilePath, int txtFileNumber) : Form(txtFilePath, txtFileNumber) {}
public:
    virtual void buttonClick() override {
        FileSplitter splitter(this->m_txtFilePath, this->m_txtFileNumber);
        cout << "file name: " << this->m_txtFilePath << "\nfile number: " << this->m_txtFileNumber << endl;
        splitter.split();
    }
};

for (int i = 0; i < n; i++) {
    for (int j = m; j >= v[i]; j--) {// j从后往前遍历
        for (int k = 0; k * v[i] <= j; k++// k枚举
            f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
    }
}

for (int i = 0; i < n; i++) {
    for (int j = v[i]; j <= m; j++)// 从前往后遍历
        f[j] = max(f[j], f[j - v[i]] + w[i]);
}