#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj1 = 0, maj2 = 1;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == maj1) cnt1++;
            else if (nums[i] == maj2) cnt2++;
            else if (cnt1 == 0) {
                maj1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                maj2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        int freq1 = 0, freq2 = 0;
        for (int num : nums) {
            if (num == maj1) freq1++;
            else if (num == maj2) freq2++;
        }

        vector<int> result;
        if (freq1 > n / 3) result.push_back(maj1);
        if (freq2 > n / 3) result.push_back(maj2);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1, 1, 2, 2, 2};
    vector<int> res = sol.majorityElement(nums);

    cout << "Majority elements (> n/3): ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}

