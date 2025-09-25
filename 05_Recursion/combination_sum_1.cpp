#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/combination-sum/
void solve(vector<int>& a, int t, int i, vector<int>& temp, vector<vector<int>>& ans) {
    if (t == 0) {
        ans.push_back(temp);
        return;
    }
    if (i >= a.size() || t < 0) return;
    temp.push_back(a[i]);
    solve(a, t - a[i], i, temp, ans);
    temp.pop_back();

    solve(a, t, i + 1, temp, ans);
}
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans, temp;
    vector<int> curr;
    solve(candidates, target, 0, curr, ans);
    for (auto& vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}

