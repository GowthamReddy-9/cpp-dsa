#include <bits/stdc++.h>
using namespace std;

// Approach: DFS traversal for all components (recursive)
class Solution {
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node, vector<int>& ans) {
        visited[node] = 1;
        ans.push_back(node);
        for (int i : adj[node]) {
            if (!visited[i])
                dfs(adj, visited, i, ans);
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(adj, visited, i, ans);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> adj = {
        {1, 2},     // 0 connected to 1, 2
        {0, 3},     // 1 connected to 0, 3
        {0},        // 2 connected to 0
        {1}         // 3 connected to 1
    };

    Solution sol;
    vector<int> res = sol.dfs(adj);

    cout << "DFS Traversal: ";
    for (int x : res) cout << x << " ";
    cout << endl;
  
    return 0;
}
