// Problem: https://leetcode.com/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[index] = nums[i];
            if (i != index) nums[i] = 0;
            index++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    moveZeroes(nums);

    for (int val : nums) cout << val << " ";
    cout << endl;
    return 0;
}

