#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st; // stores indices
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
        if (!st.empty()) nge[i] = nums[st.top()];
        st.push(i);
    }
    return nge;
}
int main() {
    vector<int> nums = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElements(nums);
    for (int x : ans) cout << x << " ";
    cout << "\n";
}

