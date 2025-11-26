// LC : https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Use Kahn's Algorithm (Topological Sort - BFS).
// Build graph b -> a for each edge [a, b] (b is prerequisite).
// Compute indegree for every course.
// Push all courses with indegree 0 into a queue and into answer.
// Process queue: pop node, reduce indegree of neighbors.
// When a neighbor's indegree becomes 0 -> push into queue & answer.
// If we processed all courses -> return ordering, else return {}.
// --------------------------------------------

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nxt : adj[node]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                    ans.push_back(nxt);
                }
            }
        }

        if (ans.size() == n) return ans;
        return {};
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> res = sol.findOrder(n, edges);

    cout << "Order: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
