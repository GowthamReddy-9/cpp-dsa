//Leetcode 785. Is Graph Bipartite?
//https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------
// Problem: Check if Graph is Bipartite (DFS approach)
// ------------------------------------------------------
// Approach:
// - Perform DFS while coloring nodes with two colors (1, 2).
// - If any edge connects nodes of the same color → not bipartite.
// - Handles disconnected graphs by checking all components.
// - Time: O(V + E), Space: O(V).

class Solution {
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& visited, int p_set) {
        visited[src] = (p_set == 1) ? 2 : 1;
        for (int nei : graph[src]) {
            if (!visited[nei]) {
                if (!dfs(nei, graph, visited, visited[src])) 
                    return false;
            } else if (visited[nei] == visited[src]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!dfs(i, graph, visited, 2)) 
                    return false;
            }
        }
        return true;
    }
};

// ------------------------------------------------------
//  Main Function (Test Case)
// ------------------------------------------------------

int main() {
    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Example 2: Non-bipartite graph (odd cycle)
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    Solution sol;

    cout << "Graph 1 is bipartite: " 
         << (sol.isBipartite(graph1) ? "true" : "false") << endl;

    cout << "Graph 2 is bipartite: " 
         << (sol.isBipartite(graph2) ? "true" : "false") << endl;

    return 0;
}
