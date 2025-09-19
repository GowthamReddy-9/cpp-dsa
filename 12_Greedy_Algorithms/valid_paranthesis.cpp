//Leetcode 678. Valid Parenthesis String
//https://leetcode.com/problems/valid-parenthesis-string/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(auto c: s){
            if(c=='('){
                mini++;
                maxi++;
            }else if(c==')'){
                mini--;
                maxi--;
            }else{
                mini--;
                maxi++;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return mini==0;
    }
};
int main()
{
    string s="(*))";
    Solution sol1;
    cout<<sol1.checkValidString(s)<<endl;
}