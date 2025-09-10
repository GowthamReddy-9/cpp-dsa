//leetcode 703
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top(); // kth largest is the smallest in heap
    }
};

int main() {
    // Example test case from LeetCode
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(k, nums);

    cout << kthLargest.add(3) << endl;  // returns 4
    cout << kthLargest.add(5) << endl;  // returns 5
    cout << kthLargest.add(10) << endl; // returns 5
    cout << kthLargest.add(9) << endl;  // returns 8
    cout << kthLargest.add(4) << endl;  // returns 8

    return 0;
}
