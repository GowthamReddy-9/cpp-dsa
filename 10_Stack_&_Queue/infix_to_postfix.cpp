#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string& s) {
    stack<char> st;
    string ans = "";
    for (char c : s) {
        if (isalnum(c)) {
            ans += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && priority(c) <= priority(st.top()) && c != '^') {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string expr = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(expr) << endl; // Output: ab/c-ak/l-*
}

