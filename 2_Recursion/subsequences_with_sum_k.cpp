/*
    Custom Problem: Print all subsequences whose sum is exactly K
    Source: Based on Take U Forward - Recursion Playlist (Video #6)

    Description:
    Given an array of integers and an integer K, print all subsequences (non-contiguous subsets)
    whose elements sum up to exactly K using recursion.
*/

#include <iostream>
#include <vector>
using namespace std;

void findSubsequencesWithSumK(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, int index, int sum, int k) {
    if (index == nums.size()) {
        if (sum == k) {
            result.push_back(temp);
        }
        return;
    }

    // Pick the current element
    temp.push_back(nums[index]);
    findSubsequencesWithSumK(nums, temp, result, index + 1, sum + nums[index], k);
    temp.pop_back();

    // Do not pick the current element
    findSubsequencesWithSumK(nums, temp, result, index + 1, sum, k);
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;

    vector<vector<int>> result;
    vector<int> temp;

    findSubsequencesWithSumK(nums, temp, result, 0, 0, k);

    cout << "Subsequences with sum = " << k << ":\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}

