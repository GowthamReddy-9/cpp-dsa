/*
    LeetCode Problem: https://leetcode.com/problems/subsets/
    Problem #78: Subsets

    Description:
    Generate all possible subsets (the power set) of a given array using recursion.
*/

#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, int index) {
    if (index == nums.size()) {
        result.push_back(temp);
        return;
    }

    // Pick
    temp.push_back(nums[index]);
    generateSubsets(nums, temp, result, index + 1);
    temp.pop_back();

    // Not Pick
    generateSubsets(nums, temp, result, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> temp;

    generateSubsets(nums, temp, result, 0);

    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}


