//Problem : Topological sort
//GFG :https://www.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Perform DFS-based Topological Sort.
// Push each node into a stack after visiting all its children.
// Finally, pop from the stack to get the topological order.
// Works only on Directed Acyclic Graphs (DAG).
// --------------------------------------------

class Solution {
  private:
    void dfs(vector<int>& visited, vector<vector<int>>& adj, int src, stack<int>& st) {
        visited[src] = 1;
        for (int i : adj[src]) {
            if (!visited[i]) dfs(visited, adj, i, st);
        }
        st.push(src);
    }

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> visited(V, 0);
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(visited, adj, i, st);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
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
