// LeetCode: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Problem: Remove Duplicates from Sorted Array II (Medium)
// Concept: Two Pointers (Slow & Fast), In-Place Modification

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();  // Edge case

    int slow = 2;  // Start from the 3rd element

    for (int fast = 2; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow - 2]) {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = removeDuplicates(nums);

    cout << "New length: " << k << "\nModified array: ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}

