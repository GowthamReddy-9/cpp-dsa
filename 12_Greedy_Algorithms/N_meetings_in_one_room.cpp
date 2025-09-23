//GFG: N meetings in one room
//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& start,vector<int>& end,int high,int low){
        int pivot=end[low];
        int i=low+1;
        int j=high;
        while(i<=j){
            while(i<=high&&end[i]<=pivot) i++;
            while(j>=low&&end[j]>pivot) j--;
            if(i<j){
                swap(end[i],end[j]);
                swap(start[i],start[j]);
            }
        }
        swap(end[low],end[j]);
        swap(start[low],start[j]);
        return j;
    }
    void quick_sort(vector<int>& start,vector<int>& end,int low,int high){
        if(low>=high) return;
        int pi=partition(start,end,high,low);
        quick_sort(start,end,low,pi-1);
        quick_sort(start,end,pi+1,high);
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        if(n==0) return 0;
        quick_sort(start,end,0,n-1);
        int ans=1;
        int last_end=end[0];
        for(int i=1; i<n; i++){
            if(start[i]>last_end){
                ans++;
                last_end=end[i];
            }
        }
        return ans;
    }
};

int main() {
    int n = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution obj;
    cout << obj.maxMeetings(start, end) << "\n";

    return 0;
}
