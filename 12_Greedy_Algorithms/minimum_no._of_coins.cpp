//GFG:Minimum number of Coins
//https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMin(int n) {
        int ans=0;
        ans+=(n/10);
        n=n%10;
        while(n){
            if(n>=5) n-=5;
            else if(n>=2) n-=2;
            else if(n>=1) n-=1;
            ans++;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    int n;
    cin>>n;
    cout<<n<<"->"<<sol.findMin(n)<<endl;
    return 0;
}