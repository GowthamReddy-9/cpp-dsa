//leetcode 3027
//https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int numberOfPairs(vector<vector<int>>& points){
        sort(points.begin(),points.end(),[](vector<int>& p,vector<int>& q){
            return (p[0]==q[0])?p[1]<q[1]:p[0]>q[0];
        });
        int n=points.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int yi=points[i][1];
            int y=INT_MAX;
            for(int j=i+1; j<n; j++){
                int yj=points[j][1];
                if(yj>yi&&y>yj){
                    ans++;
                    y=yj;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> points1 ={{6,2},{4,4},{2,6}};  //ans:2
    vector<vector<int>> points2 = {{1,5}, {2,4}, {3,3}, {4,2}, {5,1}}; //ans:4
    Solution solution;
    cout<<solution.numberOfPairs(points1)<<endl;
    cout<<solution.numberOfPairs(points2)<<endl;
    return 0;
}