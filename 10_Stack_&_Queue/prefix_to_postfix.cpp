#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        for(int i = pre_exp.size() - 1; i >= 0; i--) {
            char c = pre_exp[i];
            if(isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push(op1 + op2 + c);
            }
        }
        return st.top();
    }
};

int main() {
    Solution obj;
    string pre = "*+AB-CD";
    cout << obj.preToPost(pre) << endl;  // Expected: AB+CD-*
    return 0;
}

