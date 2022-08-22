#include <iostream>
#include <string>

using namespace std;

int helper(string& str, int start, int& cnt) {
    if (start >= str.size() - 1) return 0;// 这个返回值应该是什么 不用引用形参的话?
    int n = str.size();

    int total_cnt = 0;

    for (int i = start; i < n; i++) {
        if (i-1 >= 0 && i+1 < n && str[i-1] == 'r' && str[i] == 'e' && str[i+1] != 'd') {
            cnt++;
            char origin = str[i+1];
            str[i+1] = 'd';
            helper(str, i+1, cnt);
            str[i+1] = origin;
        }
        if (i-1 >= 0 && i+1 < n && str[i-1] == 'd' && str[i] == 'e' && str[i+1] != 'r') {
            cnt++;
            str[i+1] = 'r';
        }
        if (i-1 >= 0 && i+1 < n && str[i] == 'e' && str[i+1] == 'r' && str[i-1] != 'd') {
            cnt++;
            str[i-1] = 'd';
        }
        if (i-1 >= 0 && i+1 < n && str[i] == 'e' && str[i+1] == 'd' && str[i-1] != 'r') {
            cnt++;
            str[i-1] = 'r';
        }
    }

    return cnt;
}

int main() {
    string x = "reddee";
    int ans = helper(x);
    cout << ans << endl;

    return 0;
};