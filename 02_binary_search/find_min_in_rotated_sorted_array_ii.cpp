// LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Problem: Find Minimum in Rotated Sorted Array II (Hard)
// Concept: Binary Search with Duplicates

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int mid;

    while (l < r) {
        mid = l + (r - l) / 2;

        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            r--; // Handle duplicates
        }
    }

    return nums[l];
}

int main() {
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << "Minimum Element: " << findMin(nums) << endl;
    return 0;
}

