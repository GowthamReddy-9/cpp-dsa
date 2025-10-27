//GFG : Number of Distinct Islands
//https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------
// Problem: Number of Distinct Islands
// ------------------------------------------------------
// Approach:
// - Use DFS to traverse every island and mark visited cells.
// - Record each island’s shape using *relative coordinates*
//   (difference from the starting cell).
// - Insert each island’s normalized shape into a set to
//   automatically count only distinct island patterns.
// - Time: O(m*n), Space: O(m*n).

class Solution {
    void dfs(int row, int col,
             vector<pair<int,int>>& island,
             vector<vector<int>>& visited,
             vector<vector<int>>& grid,
             int row0, int col0, int m, int n) {

        if (row < 0 || col < 0 || row >= m || col >= n ||
            visited[row][col] || !grid[row][col])
            return;

        visited[row][col] = 1;
        island.push_back({row - row0, col - col0});

        dfs(row + 1, col, island, visited, grid, row0, col0, m, n);
        dfs(row - 1, col, island, visited, grid, row0, col0, m, n);
        dfs(row, col + 1, island, visited, grid, row0, col0, m, n);
        dfs(row, col - 1, island, visited, grid, row0, col0, m, n);
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int,int>>> distinct;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    vector<pair<int,int>> island;
                    dfs(i, j, island, visited, grid, i, j, m, n);
                    distinct.insert(island);
                }
            }
        }
        return distinct.size();
    }
};

// ------------------------------------------------------
// Main Function (Test Case)
// ------------------------------------------------------

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 1, 1}
    };

    Solution sol;
    cout << "Number of distinct islands: " 
         << sol.countDistinctIslands(grid) << endl;

    return 0;
}
