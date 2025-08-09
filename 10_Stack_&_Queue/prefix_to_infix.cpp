#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        for (int i = pre_exp.size() - 1; i >= 0; i--) {
            char c = pre_exp[i];
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push("(" + op1 + c + op2 + ")");
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string prefix = "*+AB-CD";  // Example: (A+B)*(C-D)
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << sol.preToInfix(prefix) << endl;
    return 0;
}

