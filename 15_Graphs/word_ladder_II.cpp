//Leetcode 126. Word Ladder II
//https://leetcode.com/problems/word-ladder-ii/description/

#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------
//  Approach 1 (First Attempt – Queue of Sequences)
// ------------------------------------------------------
// - Perform pure BFS where each queue element stores an entire path.
// - Works correctly and finds all shortest sequences, but memory heavy.
// - Causes MLE for large inputs because every partial path is kept in queue.

class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        queue<vector<string>> q;
        q.push({beginWord});
        wordSet.erase(beginWord);
        vector<vector<string>> ans;

        while (!q.empty()) {
            int n = q.size();
            unordered_set<string> visitedWords;
            for (int i = 0; i < n; i++) {
                vector<string> temp = q.front();
                q.pop();
                string str = temp.back();

                for (int j = 0; j < (int)str.size(); j++) {
                    char original = str[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        str[j] = c;
                        if (str == endWord) {
                            temp.push_back(endWord);
                            ans.push_back(temp);
                            temp.pop_back();
                        } else if (wordSet.count(str)) {
                            temp.push_back(str);
                            q.push(temp);
                            temp.pop_back();
                            visitedWords.insert(str);
                        }
                    }
                    str[j] = original;
                }
            }
            for (auto& w : visitedWords) wordSet.erase(w);
            if (!ans.empty()) return ans;
        }
        return {};
    }
};

// ------------------------------------------------------
//  Approach 2 (Optimal – BFS + DFS Backtracking)
// ------------------------------------------------------
// - BFS computes shortest distance (levels) for each word.
// - DFS backtracks from endWord to beginWord following valid parent links.
// - Significantly more memory-efficient and optimal (accepted solution).

class Solution2 {
    unordered_map<string, int> level;
    vector<vector<string>> ans;
    string beginWordGlobal;

    void dfs(string word, vector<string>& path, int sz) {
        if (word == beginWordGlobal) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        int steps = level[word];
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                word[i] = c;
                if (level.find(word) != level.end() && level[word] == steps - 1) {
                    path.push_back(word);
                    dfs(word, path, sz);
                    path.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        int sz = beginWord.size();

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 1;
        dict.erase(beginWord);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur == endWord) break;
            int steps = level[cur];
            for (int i = 0; i < sz; i++) {
                char original = cur[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;
                    cur[i] = c;
                    if (dict.count(cur)) {
                        level[cur] = steps + 1;
                        q.push(cur);
                        dict.erase(cur);
                    }
                }
                cur[i] = original;
            }
        }

        beginWordGlobal = beginWord;
        vector<string> path = {endWord};
        dfs(endWord, path, sz);
        return ans;
    }
};

// ------------------------------------------------------
//  Main Function (Test Case)
// ------------------------------------------------------

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution1 sol1;
    Solution2 sol2;

    cout << "=== Approach 1 (Queue of Paths) ===" << endl;
    auto res1 = sol1.findLadders(beginWord, endWord, wordList);
    for (auto& seq : res1) {
        for (auto& word : seq) cout << word << " ";
        cout << endl;
    }

    cout << "\n=== Approach 2 (BFS + DFS Optimal) ===" << endl;
    auto res2 = sol2.findLadders(beginWord, endWord, wordList);
    for (auto& seq : res2) {
        for (auto& word : seq) cout << word << " ";
        cout << endl;
    }

    return 0;
}
