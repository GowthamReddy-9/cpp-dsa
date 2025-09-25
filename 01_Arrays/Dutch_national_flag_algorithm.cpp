#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    Solution sol;
    sol.sortColors(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

