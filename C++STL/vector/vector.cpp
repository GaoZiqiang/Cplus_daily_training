#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cmpByTail(const vector<int> &x, const vector<int> &y) {
    return x[1] < y[1];
}

int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    // vector<int>::iterator it = nums.begin();
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (*it == val) {
            n--;
            nums.erase(it);
        }
    }
    return n;
}

int main(int argc, char** argv){
    // 删除指定下标元素
    std::vector<int> vec;
    for(int i=0;i<100;i++)    vec.push_back(i);
    removeElement(vec, 10);
//    for (auto it = vec.begin(); it != vec.end(); it++) {
//        if (*it == 10)
//            vec.erase(it);
//        if (*it == 20)
//            vec.erase(it);
//    }
    for (auto& x : vec) {
        printf("%d\n", x);
    }
//    printf("10:%d\n",vec[10]);
//    printf("size:%d\n",vec.size());
//    printf("**********************************\n");
//    std::vector<int>::iterator it = vec.begin()+10;
//    vec.erase(it);
//    printf("10:%d\n",vec[10]);
//    printf("size:%d\n",vec.size());
//
//    // vector数组排序
//    vector<vector<int>> intervals = {{1,2},{2,3},{1,5}};
//    sort(intervals.begin(), intervals.end(), cmpByTail);// 函数指针
//    for (int i = 0; i < intervals.size(); i++)
//        printf("intervals[0]: %d, intervals[1]: %d\n",intervals[i][0],intervals[i][1]);

    return 0;
}