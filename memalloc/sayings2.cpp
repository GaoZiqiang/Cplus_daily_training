/*saying1.cpp --using expanded String class*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string1.h"

const int ArSize = 5;
const int MaxLen = 81;

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi,what's is  your name?\n";
    cin >> name;

    cout << name << ",please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];// array of objects 这里使用默认构造函数
    char temp[MaxLen];// temporary string storage

    // 注意看，这里将i定义为一个全局变量
    int i;
    for (i = 0;i < ArSize;i ++) {
        cout << i +1 << ":";
        cin.get(temp,MaxLen);
        while(cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp;// 存入一句话
    }
    int total = i;// total # of lines read

    if(total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0;i < total;i ++) {
            cout << i + 1  << ":" << sayings[i] << endl;
        }

        // using pointers to keep track of shortest,first strings
        String *shortest = &sayings[0];
        String *first = &sayings[0];
        for (i = 1;i < total;i++) {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }

        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;
        cout << "This program used " << String::HowMany << " String objects. Bye.\n";

        srand(time(0));
        int choice = rand() % total;
        // use new to create,initialize new String object
        String *favorite = new String(sayings[choice]);// 这里使用拷贝构造函数
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;// 因为使用了new关键字，开辟了新的内存空间，因此需要显式使用delete进行删除
    }
    else
        cout << "No input! Bye.\n";

    return 0;
}