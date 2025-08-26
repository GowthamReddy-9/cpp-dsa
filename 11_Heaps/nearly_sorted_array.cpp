#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        for (int i = 0; i <= k && i < n; i++) {
            pq.push(arr[i]);
        }
        int ind = 0;
        for (int i = k + 1; i < n; i++) {
            arr[ind++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty()) {
            arr[ind++] = pq.top();
            pq.pop();
        }
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 6, 4, 5};
    int k = 2;
    Solution().nearlySorted(arr, k);
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

