// Single_Number_III.cpp
// LeetCode: https://leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xored = 0;
        for (auto it : nums) xored ^= it;

        long diffBit = (xored & (xored - 1)) ^ xored;

        int first = 0, second = 0;
        for (auto it : nums) {
            if (it & diffBit) first ^= it;
            else second ^= it;
        }

        return {first, second};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> res = sol.singleNumber(nums);
    cout << res[0] << " " << res[1] << endl;  // Output: 3 5 (or 5 3)
    return 0;
}

