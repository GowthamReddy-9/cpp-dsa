// Shortest Path Distance in DAG
// GFG : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-acyclic-graph/1

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach (Shortest Path in DAG):
// 1. Build adjacency list with weights.
// 2. Perform DFS-based Topological Sort.
//    Push each node into stack after exploring all neighbors.
// 3. Initialize distance array with -1, and set dist[src] = 0.
// 4. Pop nodes from stack in topological order:
//      If a node's distance is not -1,
//      relax all outgoing edges: dist[v] = min(dist[v], dist[u] + wt).
// 5. Return the distance array.
// This works only for DAGs (Directed Acyclic Graphs).
// --------------------------------------------

class Solution {
    void dfs(int src, vector<vector<pair<int,int>>>& adj,
             vector<int>& visited, stack<int>& st) {
        visited[src] = 1;
        for (auto &nbr : adj[src]) {
            if (!visited[nbr.first])
                dfs(nbr.first, adj, visited, st);
        }
        st.push(src);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> visited(V, 0);
        stack<int> st;

        // Topological Sort
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }

        vector<int> ans(V, -1);
        ans[0] = 0;

        // Relax edges in topo order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (ans[node] == -1) continue;

            for (auto &nbr : adj[node]) {
                int next = nbr.first;
                int wt   = nbr.second;

                if (ans[next] == -1 || ans[next] > ans[node] + wt) {
                    ans[next] = ans[node] + wt;
                }
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
    int E = 7;

    vector<vector<int>> edges = {
        {0,1,2}, {0,4,1}, {1,2,3}, {4,2,2},
        {4,5,4}, {2,3,6}, {5,3,1}
    };

    vector<int> res = sol.shortestPath(V, E, edges);

    cout << "Shortest distances: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
