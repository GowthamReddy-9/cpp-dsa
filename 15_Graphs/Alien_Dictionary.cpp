// GFG: Alien Dictionary
// GFG : https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// 1. Initialize indegree for every character appearing in any word.
// 2. Compare each pair of adjacent words to determine the first
//    differing character → that gives the directed edge u → v.
//    If no differing character exists and word1 is longer than word2,
//    it's invalid (return "").
// 3. Build adjacency list and indegree map.
// 4. Perform Kahn's Topological Sort on characters.
// 5. If result size != number of unique chars → cycle → return "".
// --------------------------------------------

class Solution {
public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Step 1: Initialize indegree for all characters
        for (auto &w : words) {
            for (char c : w) {
                if (!indegree.count(c))
                    indegree[c] = 0;
            }
        }

        // Step 2: Compare adjacent words and build edges
        int n = words.size();
        for (int i = 0; i + 1 < n; i++) {
            const string &a = words[i];
            const string &b = words[i + 1];

            int minLen = min(a.size(), b.size());
            int j = 0;

            while (j < minLen && a[j] == b[j]) j++;

            if (j < minLen) {
                char u = a[j], v = b[j];
                adj[u].push_back(v);
                indegree[v]++;
            }
            else if (a.size() > b.size()) {
                // Invalid: prefix rule violated
                return "";
            }
        }

        // Step 3: Topological Sort
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0)
                q.push(p.first);
        }

        string ans;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            ans.push_back(u);

            for (char v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 4: Check for cycle
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = sol.findOrder(words);
    cout << "Order: " << order << endl;

    return 0;
}
