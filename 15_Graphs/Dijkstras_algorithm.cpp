// Problem : Dijkstra (Two Implementations: priority_queue + set)

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Method 1: Dijkstra using priority_queue (Min-Heap)
// ------------------------------------------------------------
vector<int> dijkstra_pq(int n, vector<vector<pair<int,int>>> &adj, int src) {
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

// ------------------------------------------------------------
// Method 2: Dijkstra using set (acts like decrease-key)
// ------------------------------------------------------------
vector<int> dijkstra_set(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    set<pair<int,int>> st; // {dist, node}

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it = *st.begin();
        st.erase(st.begin());

        int d = it.first;
        int node = it.second;

        for (auto &p : adj[node]) {
            int nbr = p.first;
            int wt  = p.second;

            if (dist[nbr] > d + wt) {
                // erase old entry if exists
                if (dist[nbr] != INT_MAX)
                    st.erase({dist[nbr], nbr});

                dist[nbr] = d + wt;
                st.insert({dist[nbr], nbr});
            }
        }
    }

    return dist;
}

// ------------------------------------------------------------
// Test Both Methods
// ------------------------------------------------------------
int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    adj[0] = {{1,2}, {2,4}};
    adj[1] = {{2,1}, {3,7}};
    adj[2] = {{4,3}};
    adj[3] = {{4,1}};
    adj[4] = {};

    cout << "Priority Queue Dijkstra: ";
    vector<int> dist1 = dijkstra_pq(n, adj, 0);
    for (int d : dist1) cout << d << " ";
    cout << "\n";

    cout << "Set-Based Dijkstra:      ";
    vector<int> dist2 = dijkstra_set(n, adj, 0);
    for (int d : dist2) cout << d << " ";
    cout << "\n";

    return 0;
}
