// Problem: GFG – Rat in a Maze
// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& m, int n,
               vector<string>& res, string path, vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }

        // Down
        if (i + 1 < n && m[i + 1][j] == 1 && !vis[i + 1][j]) {
            vis[i][j] = 1;
            solve(i + 1, j, m, n, res, path + 'D', vis);
            vis[i][j] = 0;
        }

        // Left
        if (j - 1 >= 0 && m[i][j - 1] == 1 && !vis[i][j - 1]) {
            vis[i][j] = 1;
            solve(i, j - 1, m, n, res, path + 'L', vis);
            vis[i][j] = 0;
        }

        // Right
        if (j + 1 < n && m[i][j + 1] == 1 && !vis[i][j + 1]) {
            vis[i][j] = 1;
            solve(i, j + 1, m, n, res, path + 'R', vis);
            vis[i][j] = 0;
        }

        // Up
        if (i - 1 >= 0 && m[i - 1][j] == 1 && !vis[i - 1][j]) {
            vis[i][j] = 1;
            solve(i - 1, j, m, n, res, path + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            solve(0, 0, m, n, res, "", vis);
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    vector<string> paths = sol.findPath(maze, maze.size());
    for (const string& p : paths) {
        cout << p << endl;
    }

    return 0;
}

