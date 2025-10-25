//Leetcode 130. Surrounded Regions
//https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

// Approach:
// 1. Any 'O' connected to a border 'O' cannot be flipped.
// 2. Use DFS from all border 'O's to mark them as safe (e.g., '#').
// 3. After DFS, flip all remaining 'O' → 'X' (surrounded ones) and
//    convert '#' back to 'O' (safe ones).

class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#'; // mark as safe (connected to border)
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: DFS from border cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O') {
                    dfs(i, j, board);
                }
            }
        }

        // Step 2: Flip surrounded and restore safe cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original board:\n";
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }

    sol.solve(board);

    cout << "\nAfter solving:\n";
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }

    return 0;
}
