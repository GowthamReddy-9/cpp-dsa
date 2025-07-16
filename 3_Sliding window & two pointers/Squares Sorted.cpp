// LeetCode: https://leetcode.com/problems/squares-of-a-sorted-array/
// Problem: Squares of a Sorted Array
// Concept: Two Pointers from ends + Fill from back

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    vector<int> result(nums.size());
    int k = r;

    while (l <= r) {
        int leftSquare = nums[l] * nums[l];
        int rightSquare = nums[r] * nums[r];
        if (leftSquare > rightSquare) {
            result[k--] = leftSquare;
            l++;
        } else {
            result[k--] = rightSquare;
            r--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> res = sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int n : res) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

