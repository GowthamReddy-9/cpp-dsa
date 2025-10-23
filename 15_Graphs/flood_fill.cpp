//Leetcode 733. Flood Fill
//https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

// Approach:
// Use DFS to recursively fill all connected pixels that have the same initial color.
// Stop recursion when out of bounds or color mismatch. Update each valid pixel to the new color.

class Solution {
    void dfs(vector<vector<int>>& image, int row, int col, int color, int c) {
        int m = image.size(), n = image[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        if (image[row][col] != c || image[row][col] == color) return;

        image[row][col] = color;
        dfs(image, row - 1, col, color, c);
        dfs(image, row + 1, col, color, c);
        dfs(image, row, col - 1, color, c);
        dfs(image, row, col + 1, color, c);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        dfs(image, sr, sc, color, c);
        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "After Flood Fill:\n";
    for (auto& row : result) {
        for (auto& val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
