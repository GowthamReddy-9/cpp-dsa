// Problem: LeetCode #51 – N-Queens
// Link: https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> left(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
        solve(0, n, board, res, left, upperDiag, lowerDiag);
        return res;
    }

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& res,
               vector<int>& left, vector<int>& upperDiag, vector<int>& lowerDiag) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; ++row) {
            if (left[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                left[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 1;
                solve(col + 1, n, board, res, left, upperDiag, lowerDiag);
                board[row][col] = '.';
                left[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = 0;
            }
        }
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (auto& board : result) {
        for (auto& row : board)
            cout << row << endl;
        cout << endl;
    }
    return 0;
}

