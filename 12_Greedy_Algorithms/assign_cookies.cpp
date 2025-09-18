//leetcode 455
//https://leetcode.com/problems/assign-cookies/submissions/1774738661/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};
int main(){
    vector<int> g ={10,9,8,7};
    vector<int> s ={5,6,7,8,9};
    Solution sol;
    cout<<sol.findContentChildren(g,s)<<endl;
}