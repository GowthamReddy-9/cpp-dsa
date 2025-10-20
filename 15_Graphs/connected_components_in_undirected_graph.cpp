//GFG:Connected Components in an Undirected Graph
//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// Approach: 
// Build adjacency list
// Run BFS from each unvisited node to collect connected components (O(V+E))

class Solution {
    void traversal(int start_node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& res) {
        queue<int> q;
        q.push(start_node);
        visited[start_node] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }
    }

  public:
    vector<vector<int>> getComponents(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<int>> ans;
        vector<int> visited(v, 0);
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                vector<int> temp;
                traversal(i, adj, visited, temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int v = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 4}};
    vector<vector<int>> ans = s.getComponents(v, edges);

    for (auto& comp : ans) {
        for (int node : comp) cout << node << " ";
        cout << endl;
    }
    return 0;
}
