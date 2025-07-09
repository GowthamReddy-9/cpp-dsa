// Problem: LeetCode #60 – K-th Permutation Sequence
// Link: https://leetcode.com/problems/permutation-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            fact *= i;
        }
        --k;
        string res;
        for (int i = 0; i < n; ++i) {
            fact /= (n - i);
            int idx = k / fact;
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3, k = 3;
    cout << sol.getPermutation(n, k) << endl;  // Output: "213"
    return 0;
}

