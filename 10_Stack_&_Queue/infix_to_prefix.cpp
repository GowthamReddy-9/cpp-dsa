#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string toPostfix(string s) {
    string res = "";
    stack<char> st;

    for (char c : s) {
        if (isalnum(c)) {
            res += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() &&
                  (precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c != '^'))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    string postfix = toPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << endl;  // Expected: *-a/bc-/akl
}

