#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int start = 0, maxLen = 1;

    // Normal helper function to expand around center
    void expandAroundCenter(string &s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }                                         
            left--;
            right++;                          
        }									 
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        for (int i = 0; i < n; i++) {
            expandAroundCenter(s, i, i);     
            expandAroundCenter(s, i, i + 1); 
        }

        return s.substr(start, maxLen); 
    }
};
int main() {
    Solution sol;
    string input = "babad";
    cout << sol.longestPalindrome(input) << endl;  
    return 0;
}

