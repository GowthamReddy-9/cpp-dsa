// Problem : Course Schedule (Can Finish All Courses?)
// LeetCode : https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------
// Approach:
// Use Kahn's Algorithm (Topological Sort BFS).
// Each pair {a, b} means: to take course 'a' you must finish 'b' first.
// Build graph b -> a and compute indegree.
// Push all courses with indegree 0.
// Process using BFS and count how many courses are completed.
// If completed count == total courses -> possible to finish all.
// --------------------------------------------

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> Gp(numCourses);
        vector<int> in(numCourses, 0);

        for (auto &e : prerequisites) {
            Gp[e[1]].push_back(e[0]);
            in[e[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int nbr : Gp[node]) {
                in[nbr]--;
                if (in[nbr] == 0) q.push(nbr);
            }
        }

        return cnt == numCourses;
    }
};

// --------------------------------------------
// Test case
// --------------------------------------------
int main() {
    Solution sol;
    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    bool ok = sol.canFinish(numCourses, prerequisites);
    cout << (ok ? "Possible to finish all courses" : "Not possible") << endl;

    return 0;
}
