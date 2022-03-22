#include <iostream>

using namespace std;

class FileSplitter {
private:
    char* m_filePath;
    int m_fileNumber;
public:
    FileSplitter(char* filePath, int fileNumber) : m_filePath(filePath), m_fileNumber(fileNumber) {}
    void split() {
        cout << "this is FileSplitter::split()" << endl;
    }
};