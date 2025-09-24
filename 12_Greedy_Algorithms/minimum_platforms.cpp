//GFG:Minimum Platforms
//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int platforms=1;
        int result=1;
        int i=1; int j=0;
        int n=arr.size();
        while(i<n&&j<n){
            if(arr[i]<=dep[j]){
                i++;
                platforms++;
            }else{
                j++;
                platforms--;
            }
            result=max(result,platforms);
        }
        return result;
    }
};
int main()
{
    Solution obj;
    vector<int> arr={900,940,950,1100,1500,1800};
    vector<int> dep={910,1200,1120,1130,1900,2000};
    cout<<obj.minPlatform(arr,dep)<<endl;
}