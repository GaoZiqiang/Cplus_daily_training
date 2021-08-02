#include <vector>

using namespace std;

vector<int> twoSum(vector<int> numbers, int target) {
    for (int i = 0; i < numbers.size(); i++) {
        int low = i, high = numbers.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numbers[mid] == target - numbers[i])
                return {i + 1, mid + 1};
            else if (numbers[mid] < target - numbers[i])
                low = mid + 1;
            else
                hight = mid - 1;
        }
    }
}

int main() {
    int numbers = [2,7,11,15], target = 9;
    twoSum(numbers,target);
}