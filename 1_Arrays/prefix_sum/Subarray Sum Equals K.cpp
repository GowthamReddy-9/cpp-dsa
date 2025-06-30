// Leetcode 560: Subarray Sum Equals K
// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case for subarrays starting at index 0
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int rem = sum - k;
            if (prefixCount.find(rem) != prefixCount.end()) {
                count += prefixCount[rem];
            }
            prefixCount[sum]++;
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;

    Solution sol;
    cout << "Number of subarrays with sum " << k << ": " << sol.subarraySum(nums, k) << endl;

    return 0;
}

