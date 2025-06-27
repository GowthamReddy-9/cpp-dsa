// LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Problem: Longest Substring Without Repeating Characters (Medium)
// Concept: Sliding Window + Hashing Last Seen Index (ASCII based)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int hash[256];
    fill(hash, hash + 256, -1);  // Initialize all to -1

    int maxLen = 0;
    int start = 0;

    for (int r = 0; r < s.length(); r++) {
        char ch = s[r];

        // If we've seen this character and it's inside the current window
        if (hash[ch] >= start) {
            start = hash[ch] + 1;  // Shrink window
        }

        hash[ch] = r;  // Update last seen index
        maxLen = max(maxLen, r - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}

