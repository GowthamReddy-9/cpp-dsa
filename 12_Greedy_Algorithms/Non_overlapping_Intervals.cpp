//Leetcode 435:Non-overlapping Intervals
//https://leetcode.com/problems/non-overlapping-intervals/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;

        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int prevEnd = intervals[0][1];  // end of the first interval

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap → remove this interval
                ans++;
            } else {
                // No overlap → update prevEnd
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals={{1,100},{1,11},{2,11},{11,22}};
    cout<<sol.eraseOverlapIntervals(intervals);
}