#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& nums, int maxSum, int k) {
    int count = 1, sum = 0;
    for (int n : nums) {
        if (sum + n > maxSum) {
            count++;
            sum = n;
        } else {
            sum += n;
        }
    }
    return count <= k;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max(nums.begin(), nums.end());
    int high = 0;
    for (int n : nums) high += n;

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, mid, k)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "Min Largest Sum: " << splitArray(nums, k) << endl;
    return 0;
}

