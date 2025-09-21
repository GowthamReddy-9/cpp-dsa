//LeetCode 135:Candy
//https://leetcode.com/problems/candy/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) return n;

        int total = 1;  // first child gets 1 candy
        int up = 0, down = 0, peak = 0;

        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                up++;
                peak = up;
                down = 0;
                total += 1 + up;
            }
            else if(ratings[i] == ratings[i-1]) {
                up = down = peak = 0;
                total += 1;
            }
            else { // ratings[i] < ratings[i-1]
                up = 0;
                down++;
                total += 1 + down - (peak >= down ? 1 : 0);
            }
        }

        return total;
    }
};
int main(){
    vector<int> ratings={6,7,6,5,4,3,2,1,0,0,0,1,0};
    Solution sol;
    cout<<sol.candy(ratings);
    return 0;
}