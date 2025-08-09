#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> previousSmallerElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> PSE(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
        	while(!st.empty()&&st.top()>=nums[i]) st.pop();
        	if(!st.empty()) PSE[i]=st.top();
        	st.push(nums[i]);
		}
        return PSE;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 2, 10, 8}; // sample test case
    vector<int> res = sol.previousSmallerElements(nums);

    cout << "Previous Smaller Elements: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

