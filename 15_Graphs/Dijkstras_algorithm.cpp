// Problem : Dijkstra (Shortest Path in Weighted Graph)

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// 1. Use a min-heap (priority_queue with greater<>) to always pick the
//    node with the smallest current distance.
// 2. distances[] initialized to INT_MAX, except dist[src] = 0.
// 3. Pop the best (dist, node) from heap.
//    If it's outdated (d > dist[node]) → skip.
// 4. Relax edges:
//      if dist[nbr] > dist[node] + weight:
//          update and push back into heap.
// 5. Continue until heap becomes empty.
// --------------------------------------------

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &it : adj[node]) {
            int nbr = it.first;
            int wt  = it.second;

            if (dist[nbr] > d + wt) {
                dist[nbr] = d + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    return dist;
}

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0] = {{1,2}, {2,4}};
    adj[1] = {{2,1}, {3,7}};
    adj[2] = {{4,3}};
    adj[3] = {{4,1}};
    adj[4] = {};

    vector<int> dist = dijkstra(n, adj, 0);

    cout << "Distances: ";
    for (int d : dist) cout << d << " ";
    cout << endl;

    return 0;
}
