//LeetCode 45:Jump game 2
//https://leetcode.com/problems/jump-game-ii/description/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int minjumps(vector<int>& nums){
        int maxi=0;
        int curr=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(i>curr){
                ans++;
                curr=maxi;
            }
            maxi=max(maxi,i+nums[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums={1,1,1,1,1,1};
    Solution sol;
    cout<<sol.minjumps(nums);
}