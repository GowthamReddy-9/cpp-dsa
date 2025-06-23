#include <iostream>
#include <vector>
using namespace std;

vector<int> findFirstAndLast(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    int low = 0, high = nums.size() - 1;

    // Find first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
        if (nums[mid] == target) result[0] = mid;
    }

    low = 0, high = nums.size() - 1;

    // Find last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
        if (nums[mid] == target) result[1] = mid;
    }

    return result;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = findFirstAndLast(nums, target);
    cout << "First and Last Position: [" << res[0] << ", " << res[1] << "]\n";
    return 0;
}

