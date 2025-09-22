//Leetcode 57:Insert Interval
//https://leetcode.com/problems/insert-interval/description/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals,vector<int>& newInterval){
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n&&intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval={4,8};
    Solution sol;
    intervals=sol.insertInterval(intervals,newInterval);
    for(int i=0; i<intervals.size(); i++){
        cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<" ";
    }
    return 0;
}