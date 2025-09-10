//leetcode 295:find median from data stream
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<double, vector<double>, greater<double>> minheap; // right half
    priority_queue<double> maxheap; // left half
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num < maxheap.top()) 
            maxheap.push(num);
        else 
            minheap.push(num);
        
        // balance heaps
        if(maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()) 
            return (maxheap.top() + minheap.top()) / 2.0;
        else if(maxheap.size() > minheap.size()) 
            return maxheap.top();
        else 
            return minheap.top();
    }
};

int main() {
    MedianFinder mf;

    // Test case
    vector<int> nums = {5, 15, 1, 3};
    for (int num : nums) {
        mf.addNum(num);
        cout << "After inserting " << num 
             << ", current median = " << mf.findMedian() << endl;
    }

    return 0;
}
