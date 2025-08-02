#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Using sorting
    bool isAnagramSort(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    // Method 2: Using frequency array (lowercase only)
    bool isAnagramCount(string s, string t) {
        if (s.size() != t.size()) return false;
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<pair<string, string>> tests = {
        {"anagram", "nagaram"},
        {"rat", "car"},
        {"aacc", "ccac"},
        {"listen", "silent"},
        {"aa", "bb"},
        {"ab", "ba"},
        {"", ""},
        {"a", "a"}
    };

    cout << "Using Sorting:\n";
    for (int i = 0; i < tests.size(); i++) {
        string s = tests[i].first;
        string t = tests[i].second;
        cout << "isAnagramSort(\"" << s << "\", \"" << t << "\") = "
             << (obj.isAnagramSort(s, t) ? "true" : "false") << "\n";
    }

    cout << "\nUsing Frequency Array:\n";
    for (int i = 0; i < tests.size(); i++) {
        string s = tests[i].first;
        string t = tests[i].second;
        cout << "isAnagramCount(\"" << s << "\", \"" << t << "\") = "
             << (obj.isAnagramCount(s, t) ? "true" : "false") << "\n";
    }

    return 0;
}


