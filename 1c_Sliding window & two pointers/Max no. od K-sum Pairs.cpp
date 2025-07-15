// LeetCode: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Problem: Max Number of K-Sum Pairs
// Concept: Two Pointers + Greedy after Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    int operations = 0;

    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == k) {
            operations++;
            l++;
            r--;
        } else if (sum < k) {
            l++;
        } else {
            r--;
        }
    }

    return operations;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;
    cout << "Maximum operations: " << maxOperations(nums, k) << endl;
    return 0;
}

