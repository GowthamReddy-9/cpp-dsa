// LeetCode: https://leetcode.com/problems/maximum-average-subarray-i/
// Problem: Maximum Average Subarray I (Easy)
// Concept: Sliding Window (Fixed Size)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int st = 0;
    int end = 0;
    int sum = 0;
    double maxAvg = INT_MIN;

    while (end < nums.size()) {
        if (end < k) {
            sum += nums[end];
            maxAvg = sum;  // First k elements
            end++;
        } else {
            sum += nums[end++];
            sum -= nums[st++];
            if (sum > maxAvg) {
                maxAvg = sum;
            }
        }
    }

    return maxAvg / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << "Maximum Average: " << findMaxAverage(nums, k) << endl;
    return 0;
}

