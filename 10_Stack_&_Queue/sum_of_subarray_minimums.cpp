#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        stack<int> st; // stores indices of an increasing sequence

        for (int i = 0; i <= n; ++i) {
            int curr = (i < n ? arr[i] : -1); // small value to flush remaining indices
            while (!st.empty() && arr[st.top()] > curr) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                long long leftCount = mid - left;
                long long rightCount = i - mid;
                ans = (ans + (long long)arr[mid] * leftCount % MOD * rightCount % MOD) % MOD;
            }
            if (i < n) st.push(i);
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {3, 1, 2, 4};
    cout << "arr = [3,1,2,4] -> " << sol.sumSubarrayMins(arr1) << '\n'; // 17

    // Example 2 (LeetCode example)
    vector<int> arr2 = {11,81,94,43,3};
    cout << "arr = [11,81,94,43,3] -> " << sol.sumSubarrayMins(arr2) << '\n';


    return 0;
}

