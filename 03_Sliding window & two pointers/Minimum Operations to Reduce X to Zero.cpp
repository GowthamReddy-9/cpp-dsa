// LeetCode: Minimum Operations to Reduce X to Zero (1658)
// Pattern: Sliding Window + Prefix Sum Transform

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int target = total - x;
    if (target < 0) return -1;
    if (target == 0) return nums.size();

    int l = 0, sum = 0, maxLen = -1;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum > target && l <= r) {
            sum -= nums[l++];
        }
        if (sum == target) {
            maxLen = max(maxLen, r - l + 1);
        }
    }

    return (maxLen == -1) ? -1 : (int)nums.size() - maxLen;
}

int main() {
    vector<int> nums = {1,1,4,2,3};
    int x = 5;
    cout << "Min operations: " << minOperations(nums, x) << endl;
    return 0;
}

