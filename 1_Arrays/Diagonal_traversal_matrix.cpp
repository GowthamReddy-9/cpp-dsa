#include <bits/stdc++.h>
using namespace std;

class Solution {
    void upRight(vector<int>& ans, int& r, int& c, int& dir, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        while (r >= 0 && c < cols) {
            ans.push_back(mat[r][c]);
            r--; c++;
        }
        if (r < 0 && c < cols) r = 0;        // hit top
        if (c == cols) { r += 2; c = cols-1; } // hit right wall
        dir = -1;
    }

    void downLeft(vector<int>& ans, int& r, int& c, int& dir, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        while (r < rows && c >= 0) {
            ans.push_back(mat[r][c]);
            r++; c--;
        }
        if (c < 0 && r < rows) c = 0;        // hit left wall
        if (r == rows) { c += 2; r = rows-1; } // hit bottom
        dir = 1;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int r = 0, c = 0, dir = 1;
        vector<int> ans;
        ans.reserve(rows * cols);
        while (ans.size() < rows * cols) {
            if (dir == 1) upRight(ans, r, c, dir, mat);
            else downLeft(ans, r, c, dir, mat);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = s.findDiagonalOrder(mat);
    for (int x : res) cout << x << " ";
    cout << "\n";
}

