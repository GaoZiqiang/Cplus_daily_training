// 冒泡排序
void maopao(vector<int>& nums) {
    if (nums.empty()) return;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }

    return;
}
