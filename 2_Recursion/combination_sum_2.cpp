#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

void solve(vector<int>& a, int t, int i, vector<int>& temp, vector<vector<int>>& ans) {
    if (t == 0) {
        ans.push_back(temp);
        return;
    }

    for (int j = i; j < a.size(); ++j) {
        if (j > i && a[j] == a[j - 1]) continue;
        if (a[j] > t) break;
        temp.push_back(a[j]);
        solve(a, t - a[j], j + 1, temp, ans);
        temp.pop_back();
    }
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, 0, temp, ans);
    for (auto& vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}

