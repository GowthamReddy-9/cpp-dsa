// LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Problem: Two Sum II – Input Array Is Sorted (Easy)
// Concept: Two Pointers from Both Ends

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            result.push_back(i + 1); // 1-based indexing
            result.push_back(j + 1);
            return result;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }

    return result;
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}

