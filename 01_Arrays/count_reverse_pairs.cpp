#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high) {
            if (arr[left] < arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int count_pairs(vector<int>& arr, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > (long long)2 * arr[right]) {
                right++;
            }
            count += right - (mid + 1);
        }
        return count;
    }

    int merge_sort(vector<int>& arr, int low, int high) {
        int count = 0;
        if (low >= high) return count;
        int mid = (low + high) / 2;
        count += merge_sort(arr, low, mid);
        count += merge_sort(arr, mid + 1, high);
        count += count_pairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 2, 3, 1};
    int result = sol.reversePairs(nums);
    cout << "Reverse Pairs: " << result << endl;
    return 0;
}

