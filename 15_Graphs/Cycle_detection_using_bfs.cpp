// Approach:
// Use BFS to traverse each component while tracking parent nodes.
// If we encounter a visited node that is not the parent, a cycle exists.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } 
                else if (adjacentNode != parent) {
                    // Found a visited node that isn't the parent → cycle exists
                    return true;
                }
            }
        }
        return false;
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i] && detectCycle(i, adj, visited)) 
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}
    }; // This contains a cycle

    if (sol.isCycle(V, edges))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}
