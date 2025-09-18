//Leetcode 860:Lemonade change
//https://leetcode.com/problems/lemonade-change/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int n5 = 0;
        int n10 = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                n5++;
            } else if (bills[i] == 10) {
                if (n5 != 0)
                    n5--;
                else
                    return false;
                n10++;
            } else {
                if (n10 != 0) {
                    n10--;
                    if (n5 != 0)
                        n5--;
                    else
                        return false;
                } else {
                    n5 -= 3;
                    if (n5 < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
int main(){
    vector<int> bills={5,5,10,20,5,10};
    Solution sol;
    cout<<sol.lemonadeChange(bills)<<endl;
}