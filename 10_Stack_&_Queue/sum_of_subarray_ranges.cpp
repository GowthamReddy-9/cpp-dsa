#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        long long mini = 0, maxi = 0;
        int n = nums.size();

        // Pass 1: sum of subarray minimums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long ple = mid - left;
                long long nle = right - mid;
                mini += 1LL * nums[mid] * ple * nle;
            }
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Pass 2: sum of subarray maximums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long pge = mid - left;
                long long nge = right - mid;
                maxi += 1LL * nums[mid] * pge * nge;
            }
            st.push(i);
        }

        return maxi - mini;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.subArrayRanges(nums) << endl; // Expected output: 4
    return 0;
}

