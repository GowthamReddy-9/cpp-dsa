#include <bits/stdc++.h>
using namespace std;

vector<int> maxDepthAfterSplit(const string& seq) {
    vector<int> res;
    int depth = 0;
    for (char c : seq) {
        if (c == '(') {
            res.push_back(depth % 2);
            depth++;
        } else {
            depth--;
            res.push_back(depth % 2);
        }
    }
    return res;
}

int main() {
    string seq = "()(())()";
    vector<int> result = maxDepthAfterSplit(seq);
    for (int val : result) cout << val << " ";
    cout << "\n";
    return 0;
}

