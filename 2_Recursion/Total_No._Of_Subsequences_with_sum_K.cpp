/*
    Custom Problem: Count the number of subsequences whose sum is exactly K
    Source: Based on Take U Forward - Recursion Playlist (Video #7)

    Description:
    Given an array of integers and an integer K, count the number of subsequences (non-contiguous subsets)
    whose elements sum up to exactly K using recursion.
*/

#include <iostream>
#include <vector>
using namespace std;

int countSubsequencesWithSumK(vector<int>& nums, int index, int sum, int k) {
    if (index == nums.size()) {
        return (sum == k) ? 1 : 0;
    }

    // Pick the current element
    int pick = countSubsequencesWithSumK(nums, index + 1, sum + nums[index], k);

    // Do not pick the current element
    int notPick = countSubsequencesWithSumK(nums, index + 1, sum, k);

    return pick + notPick;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 4;

    int count = countSubsequencesWithSumK(nums, 0, 0, k);
    cout << "Total subsequences with sum " << k << ": " << count << endl;

    return 0;
}
