// LeetCode: https://leetcode.com/problems/container-with-most-water/
// Problem: Container With Most Water (Medium)
// Concept: Two Pointers from Both Ends, Max Area

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
        int b = r - l;
        int h = min(height[l], height[r]);
        ans = max(ans, b * h);

        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }

    return ans;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max Water Container Area: " << maxArea(height) << endl;
    return 0;
}

