// Leetcode 974: Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderFreq;
        remainderFreq[0] = 1;  // base case
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int rem = ((sum % k) + k) % k; // handles negative numbers
            if (remainderFreq.find(rem) != remainderFreq.end()) {
                count += remainderFreq[rem];
            }
            remainderFreq[rem]++;
        }

        return count;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    Solution sol;
    cout << sol.subarraysDivByK(nums, k) << endl;  // Output: 7
    return 0;
}

