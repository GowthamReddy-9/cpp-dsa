/*
    LeetCode Problem: https://leetcode.com/problems/count-number-of-nice-subarrays/
    Problem #1248: Count Number of Nice Subarrays

    Description:
    Given an array of integers and an integer k, return the number of nice subarrays —
    subarrays with exactly k odd numbers — using prefix sum + hash map.
*/

#include <iostream>
#include <vector>
using namespace std;

int countNiceSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> freq(n + 1, 0); // prefix sum count
    freq[0] = 1;

    int prefix = 0, count = 0;

    for (int num : nums) {
        prefix += (num % 2); // treat odd as 1, even as 0

        if (prefix - k >= 0) {
            count += freq[prefix - k];
        }

        freq[prefix]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Count of nice subarrays: " << countNiceSubarrays(nums, k) << endl;

    return 0;
}

