// LeetCode Problem: https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force Version (MY Implementation)
int maxSubArrayBrute(vector<int>& nums) {
    int max_sum = nums[0];
    int start = 0, end = 0;

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            if (sum > max_sum) {
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }

    cout << "Brute Force ? Subarray from index " << start << " to " << end << endl;
    return max_sum;
}

// Kadane’s Algorithm (Optimized O(n)) with Index Tracking

//int maxSubArrayKadane(vector<int>& nums) {
//    int max_sum = nums[0];
//    int current_sum = nums[0];
//    int start = 0, end = 0, temp_start = 0;
//
//    for (int i = 1; i < nums.size(); ++i) {
//        if (current_sum + nums[i] < nums[i]) {
//            current_sum = nums[i];
//            temp_start = i;
//        } else {
//            current_sum += nums[i];
//        }
//
//        if (current_sum > max_sum) {
//            max_sum = current_sum;
//            start = temp_start;
//            end = i;
//        }
//    }
//
//    cout << "Kadane’s Algo ? Subarray from index " << start << " to " << end << endl;
//    return max_sum;
//}


//Main Function

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

    int bruteResult = maxSubArrayBrute(nums);
    cout << "Maximum subarray sum (Brute Force): " << bruteResult << endl;

    //int kadaneResult = maxSubArrayKadane(nums);
  //  cout << "Maximum subarray sum (Kadane’s Algo): " << kadaneResult << endl;

    return 0;
}

