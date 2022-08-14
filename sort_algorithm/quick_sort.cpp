// 快速排序

#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int target = nums[left];
    int low = left; int high = right;

    while (low < high) {
        while (high > low && nums[high] > target) high--;
        nums[low] = nums[high];
        while (low < high && nums[low] < target) low++;
        nums[high] = nums[low];
    }

    nums[low] = target;

    return low;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left > right) return;

    int mid = partition(nums, left, right);

    quickSort(nums, left, mid-1);
    quickSort(nums, mid+1, right);

    return;
}

int main() {
    vector<int> nums = {1,5,3,2,4};

    quickSort(nums, 0, nums.size()-1);

    for (auto& n : nums) cout << n << " ";
    cout << endl;

    return 0;
}