#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        s = s + s;
        return s.find(goal) < s.size();
    }
};

int main() {
    Solution sol;
    vector<pair<string, string>> tests = {
        {"abcde", "cdeab"},      // true
        {"abcde", "abced"},      // false
        {"", ""},                // true
        {"a", "a"},              // true
        {"abc", "cab"}           // true
    };

    for (auto &p : tests) {
    string s = p.first, goal = p.second;
    cout << "s: \"" << s << "\", goal: \"" << goal << "\" -> "
         << (sol.rotateString(s, goal) ? "true" : "false") << '\n';
	}

    
    return 0;
}

