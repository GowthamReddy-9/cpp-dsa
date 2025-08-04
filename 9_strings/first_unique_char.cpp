#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    cout << sol.firstUniqChar("leetcode") << "\n";        // Output: 0
    cout << sol.firstUniqChar("loveleetcode") << "\n";    // Output: 2
    cout << sol.firstUniqChar("aabb") << "\n";            // Output: -1
    cout << sol.firstUniqChar("xxyz") << "\n";            // Output: 3
    return 0;
}

