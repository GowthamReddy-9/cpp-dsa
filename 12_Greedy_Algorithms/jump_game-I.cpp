//Leetcode 55 : Jump Game
//https://leetcode.com/problems/jump-game/description/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool canjump(vector<int>& nums){
        int n=nums.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            if(i>maxi) return false;
            maxi=max(maxi,i+nums[i]);
        }
        return true;
    }
};
int main()
{
    vector<int> nums={1,3,4,2,3};
    Solution solution;
    bool ans=solution.canjump(nums);
    cout<<ans;
    return 0;
}