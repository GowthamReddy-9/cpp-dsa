// Problem: https://leetcode.com/problems/find-peak-element/
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[mid + 1]) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Peak Index: " << findPeakElement(nums) << endl;
    return 0;
}

