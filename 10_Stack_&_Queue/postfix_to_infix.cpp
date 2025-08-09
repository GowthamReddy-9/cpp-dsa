#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postfixToInfix(string s) {
        stack<string> st;
        for (char c : s) {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                st.push("(" + op1 + c + op2 + ")");
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;

    string postfix1 = "ab+c*";  // should convert to ((a+b)*c)
    cout << "Postfix: " << postfix1 << endl;
    cout << "Infix: " << sol.postfixToInfix(postfix1) << endl;

    string postfix2 = "abc/-ak/l-*";  // should convert to ((a-(b/c))*((a/k)-l))
    cout << "Postfix: " << postfix2 << endl;
    cout << "Infix: " << sol.postfixToInfix(postfix2) << endl;

    return 0;
}

