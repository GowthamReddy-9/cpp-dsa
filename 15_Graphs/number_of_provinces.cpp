//Leetcode 547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/description/
#include <bits/stdc++.h>
using namespace std;

// Approach: DFS on adjacency matrix to count connected components (provinces)
class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int v, int n) {
        visited[v] = 1;
        for (int i = 0; i < n; i++) {
            if (isConnected[v][i] == 1 && !visited[i])
                dfs(isConnected, visited, i, n);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, visited, i, n);
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution sol;
    cout << "Number of Provinces: " << sol.findCircleNum(isConnected) << endl;

    return 0;
}
