#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Detect cycle in a Directed Graph using DFS.
// Use a 3-state visited system:
// 0 = unvisited, 1 = visiting, 2 = completely processed.
// A cycle exists if we visit a node already in the 'visiting' state.
// --------------------------------------------

class Solution {
  private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1; // mark as visiting
        for (int i : graph[node]) {
            if (!visited[i]) {
                if (dfs(i, graph, visited)) return true;
            } else if (visited[i] == 1) {
                return true; // back edge → cycle
            }
        }
        visited[node] = 2; // mark as done
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<int> visited(V, 0);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited)) return true;
            }
        }
        return false;
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 3}
    };
    cout << (sol.isCyclic(V, edges) ? "Cycle Detected" : "No Cycle") << endl;
    return 0;
}
