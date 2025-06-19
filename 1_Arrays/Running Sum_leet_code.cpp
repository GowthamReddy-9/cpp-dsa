// Problem: Running Sum of 1D Array
// Leetcode Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Logic: Each element becomes the sum of all elements before it (inclusive)

#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) { //loop starts from index 1 to avoid adding sum at index 0 .
        nums[i] += nums[i - 1]; // Cumulative sum
    }
    return nums;  
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = runningSum(nums);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

