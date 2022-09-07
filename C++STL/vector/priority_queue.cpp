#include <queue>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    priority_queue<pair<int, int>> q;
    q.push(make_pair(3,4));
    while (!q.empty()) {
        cout << q.top().first << " ";
        q.pop();
    }
}