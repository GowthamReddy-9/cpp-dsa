#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];

        heights.push_back(0); // sentinel to flush stack
        n++;

        vector<int> st;
        st.reserve(n);

        int64_t maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int h = heights[st.back()];
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                int width = i - left - 1;
                maxArea = max(maxArea, int64_t(h) * width);
            }
            st.push_back(i);
        }

        return static_cast<int>(maxArea);
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}

