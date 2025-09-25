#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 4, -1, 1},
        {1, 2, 0},
        {7, 8, 9, 11, 12},
        {2, 5, 4, 6, 1, 7},    // missing number in middle
        {1, 2, 3, 4, 5},
        {1000000, 999999, 1}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << "\nFirst Missing Positive: " << sol.firstMissingPositive(nums) << "\n\n";
    }

    return 0;
}

