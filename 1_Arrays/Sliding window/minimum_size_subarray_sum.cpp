// LeetCode: https://leetcode.com/problems/minimum-size-subarray-sum/
// Problem: Minimum Size Subarray Sum (Medium)
// Concept: Sliding Window (Variable Size)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int temp = INT_MAX;
    int st = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        while (sum >= target) {
            int size = i + 1 - st;
            if (size < temp) {
                temp = size;
            }
            sum -= nums[st++];
        }
    }

    return (temp < INT_MAX) ? temp : 0;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum Length Subarray Sum >= " << target << " is: " << minSubArrayLen(target, nums) << endl;
    return 0;
}

