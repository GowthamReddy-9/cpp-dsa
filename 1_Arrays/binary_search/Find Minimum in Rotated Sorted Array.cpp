// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r]) l = mid + 1;
        else r = mid;
    }
    return nums[l];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Minimum: " << findMin(nums) << endl;
    return 0;
}

