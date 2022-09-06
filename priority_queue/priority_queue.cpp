#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

//bool cmp(int a, int b) {
//    return a > b;
//}
struct cmp {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    priority_queue<int, vector<int>, cmp> s;

    vector<int> vec = {1,3, 2, 7, 5, 43, 443};

    for (auto& x : vec) {
        s.push(x);
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}