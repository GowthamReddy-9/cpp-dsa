#include <bits/stdc++.h>
using namespace std;

// Removes the outermost parentheses from each primitive valid substring
void removeOuterParentheses(string& s) {
    int balance = 0, write = 0;
    for (int read = 0; read < s.size(); ++read) {
        if (s[read] == '(') {
            if (balance > 0) s[write++] = '(';
            balance++;
        } else {
            balance--;
            if (balance > 0) s[write++] = ')';
        }
    }
    s.resize(write);
}

// Test harness
int main() {
    vector<string> tests = {
        "(()())(())",
        "(()())(())(()(()))",
        "()()"
    };

    for (string& s : tests) {
        string original = s;
        removeOuterParentheses(s);
        cout << "Input:    " << original << '\n';
        cout << "Output:   " << s << "\n\n";
    }

    return 0;
}

