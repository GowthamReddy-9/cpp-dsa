// Leetcode 303: Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefix;  // Stores the prefix sum array

public:
    NumArray(vector<int>& nums) {
        prefix = nums;
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] += prefix[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefix[right];
        return prefix[right] - prefix[left - 1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << endl; // Output: 1
    cout << obj->sumRange(2, 5) << endl; // Output: -1
    cout << obj->sumRange(0, 5) << endl; // Output: -3
    delete obj;
    return 0;
}

