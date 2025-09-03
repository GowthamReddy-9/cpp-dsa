#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Two-pointer technique (O(n) time, O(1) space)
    int trapTwoPointers(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0, total = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lmax)
                    total += lmax - height[l];
                else
                    lmax = height[l];
                l++;
            } else {
                if (height[r] < rmax)
                    total += rmax - height[r];
                else
                    rmax = height[r];
                r--;
            }
        }
        return total;
    }

    // Approach 2: Monotonic stack (O(n) time, O(n) space)
    int trapStack(vector<int>& height) {
        int n = height.size(), total = 0;
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                total += distance * bounded_height;
            }
            st.push(i);
        }
        return total;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Two-pointer method: " << sol.trapTwoPointers(height) << endl;
    cout << "Monotonic stack method: " << sol.trapStack(height) << endl;

    return 0;
}

