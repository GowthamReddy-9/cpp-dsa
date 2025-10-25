//Leetcode 542. 01 Matrix
//https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

// Approach:
// Perform a multi-source BFS starting from all cells with 0.
// 1s are initialized as -1 (unvisited). Each BFS level increases distance by 1.
// This ensures each cell gets the shortest distance to the nearest 0.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;

        // Step 1: Push all 0s to queue and mark 1s as -1 (unvisited)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        // Step 2: BFS from all 0s simultaneously
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && mat[newRow][newCol] == -1) {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return mat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans = sol.updateMatrix(mat);

    cout << "Updated Matrix:\n";
    for (auto& row : ans) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
