// File: 9_strings/Group_Anagrams.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& it : group) {
            result.push_back(move(it.second)); // optional optimization
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = sol.groupAnagrams(input);

    for (const auto& group : grouped) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

