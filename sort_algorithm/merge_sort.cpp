// 归并排序

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& origin, int low, int mid, int high) {
    vector<int> copy(origin);

    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (origin[i] < origin[j]) {
            copy[k++] = origin[i++];
        } else {
            copy[k++] = origin[j++];
        }
    }

    while (i <= mid) copy[k++] = origin[i++];
    while (j <= high) copy[k++] = origin[j++];

    for (int i = low; i <= high; i++) origin[i] = copy[i];

    return;
}

void mergeSort(vector<int>& origin, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(origin, low, mid);
    mergeSort(origin, mid+1, high);
    merge(origin, low, mid, high);

    return;
}

int main() {
    vector<int> nums = {1, 4, 3, 2, 5};

    mergeSort(nums, 0, nums.size() - 1);

    for (auto& n : nums) cout << n << " ";
    cout << endl;

    return 0;
}