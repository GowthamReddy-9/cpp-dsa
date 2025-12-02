// Shortest Path in Undirected Unit Distance Graph
// GFG : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Use BFS because every edge has weight = 1.
// 1. Build adjacency list for the undirected graph.
// 2. Use a queue storing {node, distance}.
// 3. Initialize ans[src] = 0 and push src.
// 4. For each neighbor:
//      - If not visited (ans == -1) OR found a shorter path,
//        update distance and push into queue.
// 5. BFS ensures shortest path for unit-weight graphs.
// --------------------------------------------

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<int> ans(V, -1);
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        ans[src] = 0;
        q.push({src, 0});

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            for (int nbr : adj[node]) {
                if (ans[nbr] == -1 || ans[nbr] > dist + 1) {
                    ans[nbr] = dist + 1;
                    q.push({nbr, ans[nbr]});
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

    int V = 6, src = 0;
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,4}, {3,5}, {4,5}
    };

    vector<int> res = sol.shortestPath(V, edges, src);

    cout << "Shortest distances: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
