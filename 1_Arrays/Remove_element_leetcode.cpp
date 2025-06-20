// LeetCode Problem: https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>
using namespace std;

void removeElement(vector<int>& nums, int val) {
    int w = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[w] = nums[i];
            w++;
        }
    }
    nums.resize(w);
}

int main() {
    int n, val;
    vector<int> nums;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << "Enter value to remove: ";
    cin >> val;

    removeElement(nums, val);

    cout << "Array after removing " << val << ":\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
} 

