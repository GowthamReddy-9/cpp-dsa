#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimal: Column-scan approach
    string longestCommonPrefix_scan(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c)
                    return ans;
            }
            ans += c;
        }
        return ans;
    }

    // Sort-based: Compare first and last after sorting
    string longestCommonPrefix_sort(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs.back();
        string ans = "";
        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] != b[i]) break;
            ans += a[i];
        }
        return ans;
    }
};

void test(vector<string> strs) {
    Solution sol;
    cout << "Input: ";
    for (auto& s : strs) cout << "\"" << s << "\" ";
    cout << "\n";

    cout << "Scan-based Prefix: " << sol.longestCommonPrefix_scan(strs) << "\n";
    cout << "Sort-based Prefix: " << sol.longestCommonPrefix_sort(strs) << "\n";
    cout << "--------------------------\n";
}

int main() {
    test({"flower", "flow", "flight"});
    test({"dog", "racecar", "car"});
    test({"interstellar", "internet", "internal", "interval"});
    test({"a"});
    test({"prefix", "prefixes", "pref", "pre"});
    return 0;
}

