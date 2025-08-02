#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<char> hashArr(128, '.');
        vector<char> mapped(128, '.');
        for (int i = 0; i < n; i++) {
            if (hashArr[s[i]] == '.' && mapped[t[i]] == '.') {
                hashArr[s[i]] = t[i];
                mapped[t[i]] = s[i];
            } else {
                if (hashArr[s[i]] != t[i] || mapped[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<pair<string, string>> testcases = {
        {"egg", "add"},       // true
        {"foo", "bar"},       // false
        {"paper", "title"},   // true
        {"ab", "aa"},         // false
        {"badc", "baba"}      // false
    };

    for (auto &p : testcases) {
    string s = p.first;
    string t = p.second;
    cout << "s = " << s << ", t = " << t << " ? "<< (sol.isIsomorphic(s, t) ? "true" : "false") << endl;
    }

    return 0;
}

