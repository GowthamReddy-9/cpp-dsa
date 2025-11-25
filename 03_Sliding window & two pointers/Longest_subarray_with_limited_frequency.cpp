// Problem : Longest Subarray With Limited Frequency
// LeetCode : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Sliding Window + Frequency Map.
// Expand right pointer and count freq of nums[r].
// If freq > k, shrink from left until valid.
// Track maximum window size.
// --------------------------------------------

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> freq;

        for (int l = 0, r = 0; r < n; r++) {
            freq[nums[r]]++;

            while (freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1, 2, 3, 1};
    int k = 2;

    int res = sol.maxSubarrayLength(nums, k);
    cout << "Max Subarray Length: " << res << endl;

    return 0;
}
