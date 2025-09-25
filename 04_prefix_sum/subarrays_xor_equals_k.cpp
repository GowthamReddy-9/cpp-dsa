#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        int xr = 0;
        freq[0] = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i];
            count += freq[xr ^ k];
            freq[xr]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Count of subarrays with XOR = " << k << " is: " << sol.subarrayXor(arr, k) << endl;
    return 0;
}

