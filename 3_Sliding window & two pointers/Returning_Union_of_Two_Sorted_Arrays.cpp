#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        //using two pointer approach by taking advantage of sorted arrays.
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (res.empty() || res.back() != nums1[i])   
                    res.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                if (res.empty() || res.back() != nums2[j])   //if elements in both arr1&arr2 are left.
                    res.push_back(nums2[j]);
                j++;
            } else {
                if (res.empty() || res.back() != nums1[i])
                    res.push_back(nums1[i]);
                i++, j++;
            }
        }
        while (i < nums1.size()) {
            if (res.empty() || res.back() != nums1[i])  //if only arr2 exhausted.
                res.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) {
            if (res.empty() || res.back() != nums2[j])	//if only arr1 exhausted.
                res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 5, 6};

    vector<int> result = sol.unionArray(nums1, nums2);

    cout << "Union: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

