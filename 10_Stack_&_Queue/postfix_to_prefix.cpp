#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postToPre(string post_exp) {
        stack<string> st;
        for (char c : post_exp) {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push(c + op2 + op1);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string postfix = "AB+CD-*";
    cout << sol.postToPre(postfix) << endl;  // Expected: *+AB-CD
    return 0;
}

