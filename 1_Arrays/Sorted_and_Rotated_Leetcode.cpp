// LeetCode Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <iostream>
#include <vector>
using namespace std;

bool checkSortedAndRotated(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            count++;
        }
    }
    if (nums[nums.size() - 1] > nums[0]) {
        count++;
    }
    return count <= 1;
}
/*
ChatGpt Optimized Version
bool checkSortedAndRotated(vector<int>& nums) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    return count <= 1;
}

*/
int main() {
    int n;
    vector<int> nums;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    bool isSortedRotated = checkSortedAndRotated(nums);

    if (isSortedRotated) {
        cout << "Array is sorted and rotated." << endl;
    } else {
        cout << "Array is NOT sorted and rotated." << endl;
    }

    return 0;
    
}

