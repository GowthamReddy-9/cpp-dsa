#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Max Heap of size n
    int findKthLargestMaxHeap(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end()); // max heap
        for (int i = 1; i < k; i++) pq.pop();
        return pq.top();
    }

    // Approach 2: Min Heap of size k (better)
    int findKthLargestMinHeap(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int x : nums) {
            pq.push(x);
            if ((int)pq.size() > k) pq.pop(); // keep only k largest
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {3,2,1,5,6,4};
    int k1 = 2;
    cout << "MaxHeap approach: " << sol.findKthLargestMaxHeap(nums1, k1) << endl;
    cout << "MinHeap approach: " << sol.findKthLargestMinHeap(nums1, k1) << endl;

    vector<int> nums2 = {7,10,4,3,20,15};
    int k2 = 3;
    cout << "MaxHeap approach: " << sol.findKthLargestMaxHeap(nums2, k2) << endl;
    cout << "MinHeap approach: " << sol.findKthLargestMinHeap(nums2, k2) << endl;

    return 0;
}

