#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

// s：母 p：子
int solve(string& s, string& p) {
    int n = s.size(), m = p.size();
    if (m == 0 || m > n) return false;

    set<char> set;
    for (auto& x : p) set.insert(x);
    unordered_map<char, int> umap;

    int i = 0;
    int j = 0;
    int sidx = -1;
    while (i < n && j < m) {
        cout << "1" << endl;
        if (j == m) {
            cout << "end" << endl;
            return sidx;
        }
        if (j == 0 && set.count(s[i]) != 0) {
            umap.clear();
            for (auto& x : umap) cout << x.first << " " << x.second << endl;
//            for (auto x : umap) x.second = 0;
            if (umap.count(s[i]) == 0) {
                umap[s[i]]++;
                sidx = i;
                i++;
                j++;
            } else {
                j = 0;
                i++;
            }
        }
        if (i - 1 >= 0 && j > 0 && set.count(s[i-1]) != 0 && set.count(s[i]) != 0) {
            if (umap.count(s[i]) == 0) {
                umap[s[i]]++;
                i++;
                j++;
            } else {
                j = 0;
                i++;
            }

        }
    }

    return -1;
}

int main() {
    string s = "a";// 母
    string p = "a";// 子
//    cout << "1" << endl;
    cout << solve(s, p) << endl;
}