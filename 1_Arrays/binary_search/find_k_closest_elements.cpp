// LeetCode: https://leetcode.com/problems/find-k-closest-elements/
// Problem: Find K Closest Elements (Medium)
// Concept: Binary Search + Shrinking Window

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> result;
    int l = 0;
    int r = arr.size() - 1;

    while (r - l + 1 > k) {
        if (abs(arr[l] - x) > abs(arr[r] - x)) {
            l++;
        } else {
            r--;
        }
    }

    for (int i = l; i <= r; i++) {
        result.push_back(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = findClosestElements(arr, k, x);
    cout << "K Closest Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

