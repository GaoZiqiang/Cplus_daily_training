// vector插入多个元素

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> words = {"one", "two", "three", "eight"};
    for (auto w : words) cout << w << " ";
    cout << endl;

    // 插入一个由第二个和第三个参数指定的元素序列
    std:: string more[] {"five", "six", "seven" }; // Array elements to be inserted
    auto iter = words.insert(std::end(words) , std::begin(more), std::end(more));
    for (auto w : words) cout << w << " ";
    cout << endl;

    // 在插入点插入多个单个元素。第二个参数是第三个参数所指定对象的插入次数
    iter = words.insert(std::cend(words), 2, "nine");
    for (auto w : words) cout << w << " ";
    cout << endl;
}

