#include <iostream>
#include "progresses.h"
#include "iprogress.h"

using namespace std;

class FileSplitter {
private:
    char* m_filePath;
    int m_fileNumber;

//    ProgressBar* m_progressBar;
public:
    FileSplitter(char* filePath, int fileNumber) : m_filePath(filePath), m_fileNumber(fileNumber) {}
    void split(IProgress* iProgress) {
//        cout << "this is FileSplitter::split()" << endl;
        iProgress->doProgress(this->m_fileNumber);
    }
};