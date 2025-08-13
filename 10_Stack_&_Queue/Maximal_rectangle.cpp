#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    // Histogram largest rectangle
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.push_back(0); // sentinel to flush stack
        vector<int> st;
        int64_t maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.back()] > heights[i])) {
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

    // Maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int64_t ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            ans = max(ans, int64_t(largestRectangleArea(heights)));
        }

        return static_cast<int>(ans);
    }
};

// For local testing
int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}

