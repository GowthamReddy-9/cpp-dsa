#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/subsets-ii/

void generate(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& ans) {
    ans.push_back(temp);
    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        temp.push_back(nums[i]);
        generate(nums, i + 1, temp, ans);
        temp.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 2};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    generate(nums, 0, temp, ans);
    for (auto& vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    return 0;
}

