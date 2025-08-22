#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq; // max-heap
        for (int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution obj;
    cout << "Kth smallest element is: " << obj.kthSmallest(arr, k) << endl;

    return 0;
}

