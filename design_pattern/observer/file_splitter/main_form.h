#include <string>
#include <vector>

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
    MainForm(char* txtFilePath, int txtFileNumber) : Form(txtFilePath, txtFileNumber) {
    }
//    IProgress* m_iProgress;
    vector<IProgress*> progress;
public:
    void add(IProgress* iProgress) {
        progress.push_back(iProgress);
    }
    void remove(IProgress* iProgress) {
        for (auto it = progress.begin(); it != progress.end(); it++) {
            if ((*it) = iProgress) {
                it = progress.erase(it);
                break;
            }
        }
//        std::remove(iProgress);
    }
    virtual void buttonClick() override {
        FileSplitter splitter(this->m_txtFilePath, this->m_txtFileNumber);
//        cout << "file name: " << this->m_txtFilePath << "\nfile number: " << this->m_txtFileNumber << endl;
        for (auto& x : progress)
            splitter.split(x);
    }
};