//Leetcode 994. Rotting Oranges
//https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

// Approach: Multi-source BFS from all rotten oranges, spreading level by level.
// Track fresh count to avoid extra grid scan and increment time after each layer.
// Stop when no fresh oranges remain or queue is empty.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time = 0, fresh = 0;
        int m = grid.size(), n = grid[0].size();

        // Push initial rotten oranges & count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        // BFS
        while (!q.empty() && fresh) {
            int v = q.size();
            for (int i = 0; i < v; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (row > 0 && grid[row - 1][col] == 1) {
                    q.push({row - 1, col});
                    grid[row - 1][col] = 2;
                    fresh--;
                }
                if (row < m - 1 && grid[row + 1][col] == 1) {
                    q.push({row + 1, col});
                    grid[row + 1][col] = 2;
                    fresh--;
                }
                if (col > 0 && grid[row][col - 1] == 1) {
                    q.push({row, col - 1});
                    grid[row][col - 1] = 2;
                    fresh--;
                }
                if (col < n - 1 && grid[row][col + 1] == 1) {
                    q.push({row, col + 1});
                    grid[row][col + 1] = 2;
                    fresh--;
                }
            }
            time++;
        }

        return fresh ? -1 : time;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution sol;
    cout << "Minutes until all oranges rot: " << sol.orangesRotting(grid) << endl;
    return 0;
}
