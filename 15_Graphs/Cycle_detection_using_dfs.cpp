// Approach:
// DFS with parent tracking. For each neighbor:
//  - if unvisited: recurse and if recursion finds a cycle, return true.
//  - else (already visited) and not parent -> cycle found.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detectCycle(int src, int parent, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = 1;
        for (auto adjacencyNode : adj[src]) {
            if (!visited[adjacencyNode]) {
                if (detectCycle(adjacencyNode, src, adj, visited))
                    return true;
            } else if (adjacencyNode != parent) {
                return true;
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
            if (!visited[i] && detectCycle(i, -1, adj, visited))
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Testcase 1: contains a cycle (1-2-3-4-1)
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}
    };
    cout << (sol.isCycle(V1, edges1) ? "Cycle detected\n" : "No cycle detected\n");

    // Testcase 2: no cycle (a simple tree)
    int V2 = 5;
    vector<vector<int>> edges2 = {
        {0,1}, {0,2}, {1,3}, {1,4}
    };
    cout << (sol.isCycle(V2, edges2) ? "Cycle detected\n" : "No cycle detected\n");

    return 0;
}
