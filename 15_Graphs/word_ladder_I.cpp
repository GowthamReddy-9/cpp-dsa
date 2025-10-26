//LeetCode 127. Word Ladder
//https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Use Bidirectional BFS from both beginWord and endWord.
- Always expand the smaller frontier to minimize search space.
- For each word, try changing every character (a–z) and check if it exists in the word list.
- When both searches meet, we’ve found the shortest transformation sequence.

Time:  O(N * L * 26)   where N = number of words, L = word length
Space: O(N)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        wordSet.erase(beginWord);
        wordSet.erase(endWord);

        int ans = 1; // start from beginWord

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand smaller frontier
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextLevel;
            for (string s : beginSet) {
                int n = s.size();
                for (int i = 0; i < n; i++) {
                    char original = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        s[i] = c;

                        // If we meet from both ends
                        if (endSet.count(s)) return ans + 1;

                        // Valid next step
                        if (wordSet.count(s)) {
                            nextLevel.insert(s);
                            wordSet.erase(s);
                        }
                    }
                    s[i] = original;
                }
            }
            beginSet = nextLevel;
            ans++;
        }

        return 0;
    }
};

// ---------- Test ----------
int main() {
    Solution obj;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << "Shortest transformation length: "
         << obj.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
