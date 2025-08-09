#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() { }

    void push(long long val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else if (val >= mini) {
            st.push(val);
        } else {
            st.push(2*val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.top() < mini) {
            mini = 2*mini - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() >= mini) return st.top();
        return mini;
    }

    int getMin() {
        return mini;
    }
};

int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.getMin() << "\n"; // -3
    st.pop();
    cout << st.top() << "\n";    // 0
    cout << st.getMin() << "\n"; // -2
}

