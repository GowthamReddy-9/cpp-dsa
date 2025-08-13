// LeetCode 901 - Online Stock Span
// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; // {price, span}

public:
    StockSpanner() {
        // Constructor initializes empty stack
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

// Example usage
int main() {
    StockSpanner sp;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << sp.next(price) << " ";
    }
    // Output: 1 1 1 2 1 4 6
    return 0;
}

