#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    double gain(int p,int t){
    return (double)(p+1)/t+1 - (double)(p)/t;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;
        double total_sum=0.0;
        for(auto it:classes){
            int p=it[0];
            int t=it[1];
            pq.push({gain(p,t),{p,t}});
        }
        while(extraStudents-->0){
            auto top=pq.top(); pq.pop();
            int p=top.second.first;
            int t=top.second.second;
            p++;
            t++;
            pq.push({gain(p,t),{p,t}});
        }
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            int p=top.second.first;
            int t=top.second.second;
            total_sum+=(double)(p)/t;
        }
        return total_sum/n;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> classes;
    for(int i=0; i<n; i++){
        vector<int> cls;
        int p,t;
        cin>>p;
        cin>>t;
        cls.push_back(p);
        cls.push_back(t);
        classes.push_back(cls);
    }
    int extra;
    cin>>extra;
    Solution solution;
    cout<<solution.maxAverageRatio(classes,extra);
}