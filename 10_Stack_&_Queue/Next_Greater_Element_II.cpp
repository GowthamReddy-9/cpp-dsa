#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGE(n, -1);
        stack<int> st;
        for (int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx])
                st.pop();
            if (i < n && !st.empty())
                NGE[idx] = st.top();
            st.push(nums[idx]);
        }
        return NGE;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> res = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

