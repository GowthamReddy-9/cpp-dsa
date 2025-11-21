// Problem : Cycle Detection in Directed Graph (Kahn's Algorithm - BFS)
// GFG : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Use Kahn's Algorithm (Topological BFS) to detect a cycle.
// Compute indegree of all nodes.
// Push all nodes with indegree 0 into a queue.
// Pop nodes one by one and reduce indegree of neighbors.
// Count how many nodes are processed.
// If processed count < V -> cycle exists.
// --------------------------------------------

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);
        vector<int> in(V, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in[i] == 0) q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int nbr : adj[node]) {
                in[nbr]--;
                if (in[nbr] == 0) q.push(nbr);
            }
        }

        return cnt != V;   // true -> cycle exists
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}
    };

    bool hasCycle = sol.isCyclic(V, edges);
    cout << (hasCycle ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}
