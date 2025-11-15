// Problem : Topological sort (Kahn's Algorithm - BFS)
// GFG : https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Perform BFS-based Topological Sort using Kahn's Algorithm.
// Compute indegree of each node.
// Push all nodes with indegree 0 into a queue.
// Pop from queue → add to answer → reduce indegree of neighbours.
// Works only on Directed Acyclic Graphs (DAG).
// --------------------------------------------

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int nxt : adj[node]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
        }

        return ans;
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    vector<int> res = sol.topoSort(V, edges);
    cout << "Topological Order: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
