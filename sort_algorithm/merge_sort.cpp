// 归并排序

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int low, int high) {
    int mid = (low + high) / 2;
    vector<int> copy(nums);

    int i = low, j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (nums[i] < nums[j]) copy[k++] = nums[i++];
        else copy[k++] = nums[j++];
//        i++;j++;
    }

    while (i <= mid) copy[k++] = nums[i++];
    while (j <= high) copy[k++] = nums[j++];

    for (int i = low; i <= high; i++) nums[i] = copy[i];

    return;
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    // 分
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    // merge
    merge(nums, low, high);
}

int main() {
    vector<int> nums = {1, 4, 3, 2, 5};

    mergeSort(nums, 0, nums.size() - 1);

    for (auto& n : nums) cout << n << " ";
    cout << endl;

    return 0;
}