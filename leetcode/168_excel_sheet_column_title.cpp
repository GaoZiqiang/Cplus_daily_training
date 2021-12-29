/* leetcode T168:Excel表列名称
 * 原题链接：https://leetcode-cn.com/problems/excel-sheet-column-title/
 * */

#include <string>
#include <iostream>

using namespace std;

string convertToTile(int columnNumber) {
    string ans;
    while (columnNumber--) {
        ans += columnNumber % 26 + 'A';
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << convertToTile(28) << endl;
}